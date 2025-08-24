#ifndef TERMINAL_H
#define TERMINAL_H

#include "core/object/ref_counted.h"  // ✅ Use RefCounted for GDScript usability
#include "core/object/class_db.h"     // ✅ Required for ClassDB and D_METHOD
#include "core/string/ustring.h"

class Terminal : public RefCounted {
    GDCLASS(Terminal, RefCounted);

protected:
    static void _bind_methods();

public:
    String run_command(const String &cmd);
};

#endif
