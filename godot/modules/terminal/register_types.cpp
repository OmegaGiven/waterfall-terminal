#include "register_types.h"
#include "terminal.h"
#include "core/object/class_db.h"


void initialize_terminal_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    ClassDB::register_class<Terminal>();
}

void uninitialize_terminal_module(ModuleInitializationLevel p_level) {
    // Optional cleanup
}
