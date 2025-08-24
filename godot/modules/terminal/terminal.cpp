#include "terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <array>
#include "core/object/class_db.h"


void Terminal::_bind_methods() {
    ClassDB::bind_method(D_METHOD("run_command", "cmd"), &Terminal::run_command);
}

String Terminal::run_command(const String &cmd) {
    std::string result;
    std::array<char, 128> buffer;
    FILE *pipe = popen(cmd.utf8().get_data(), "r");
    if (!pipe) return "Failed to run command";

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }

    pclose(pipe);
    return String(result.c_str());
}