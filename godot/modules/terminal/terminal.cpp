#include "terminal.h"
#include <unistd.h>
#include <fcntl.h>
#include <pty.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void Terminal::_bind_methods() {
    ClassDB::bind_method(D_METHOD("start_shell"), &Terminal::start_shell);
    ClassDB::bind_method(D_METHOD("send_command", "cmd"), &Terminal::send_command);
    ClassDB::bind_method(D_METHOD("get_current_directory"), &Terminal::get_current_directory);
    ClassDB::bind_method(D_METHOD("stop_shell"), &Terminal::stop_shell);
}

Terminal::Terminal() {}

Terminal::~Terminal() {
    stop_shell();
}

void Terminal::start_shell() {
    if (master_fd != -1) return;

    shell_pid = forkpty(&master_fd, nullptr, nullptr, nullptr);
    if (shell_pid == 0) {
        execl("/bin/bash", "bash", nullptr);
        exit(1);
    }

    fcntl(master_fd, F_SETFL, O_NONBLOCK);
}

Dictionary Terminal::send_command(const String &cmd) {
    Dictionary result;

    if (master_fd == -1) {
        result["success"] = false;
        result["output"] = "Shell not started";
        return result;
    }

    std::string command = cmd.utf8().get_data();
    command += "\n";
    write(master_fd, command.c_str(), command.size());

    std::string output;
    char buffer[256];
    usleep(100000);

    ssize_t bytes_read;
    while ((bytes_read = read(master_fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        output += buffer;
    }

    result["success"] = true;
    result["output"] = String(output.c_str());

    // Optional: update current directory if command was 'cd'
    if (cmd.begins_with("cd ")) {
        current_directory = cmd.substr(3).strip_edges();
    }

    return result;
}

String Terminal::get_current_directory() const {
    return current_directory;
}

void Terminal::stop_shell() {
    if (master_fd != -1) {
        close(master_fd);
        master_fd = -1;
    }
}
