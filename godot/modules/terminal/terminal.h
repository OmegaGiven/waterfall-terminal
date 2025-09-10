#ifndef TERMINAL_H
#define TERMINAL_H

#include "core/object/ref_counted.h"
#include "core/variant/dictionary.h"
#include "core/string/ustring.h"

#include <unistd.h>
#include <fcntl.h>
#include <pty.h>
#include <sys/types.h>
#include <sys/wait.h>

class Terminal : public RefCounted {
    GDCLASS(Terminal, RefCounted);

private:
    int master_fd = -1;
    pid_t shell_pid = -1;
    String current_directory;

protected:
    static void _bind_methods();

public:
    Terminal();
    ~Terminal();

    void start_shell();
    Dictionary send_command(const String &cmd);
    String get_current_directory() const;
    void stop_shell();
};

#endif // TERMINAL_H
