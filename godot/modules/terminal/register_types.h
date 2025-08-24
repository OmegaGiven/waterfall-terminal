#ifndef TERMINAL_REGISTER_TYPES_H
#define TERMINAL_REGISTER_TYPES_H

#include "modules/register_module_types.h" // Required for ModuleInitializationLevel

void initialize_terminal_module(ModuleInitializationLevel p_level);
void uninitialize_terminal_module(ModuleInitializationLevel p_level);

#endif
