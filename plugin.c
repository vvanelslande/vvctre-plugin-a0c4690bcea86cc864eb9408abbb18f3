// Copyright 2020 Valentin Vanelslande
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common_types.h"

#ifdef _WIN32
#define VVCTRE_PLUGIN_EXPORT __declspec(dllexport)
#else
#define VVCTRE_PLUGIN_EXPORT
#endif

static const char* required_function_names[] = {
    "vvctre_settings_set_resolution",
    "vvctre_settings_set_use_custom_layout",
    "vvctre_settings_set_custom_layout_top_left",
    "vvctre_settings_set_custom_layout_top_top",
    "vvctre_settings_set_custom_layout_top_right",
    "vvctre_settings_set_custom_layout_top_bottom",
    "vvctre_settings_set_custom_layout_bottom_left",
    "vvctre_settings_set_custom_layout_bottom_top",
    "vvctre_settings_set_custom_layout_bottom_right",
    "vvctre_settings_set_custom_layout_bottom_bottom",
    "vvctre_settings_set_nickname",
};

typedef void (*vvctre_settings_set_resolution_t)(u16 value);
static vvctre_settings_set_resolution_t vvctre_settings_set_resolution;
typedef void (*vvctre_settings_set_use_custom_layout_t)(bool value);
static vvctre_settings_set_use_custom_layout_t vvctre_settings_set_use_custom_layout;
typedef void (*vvctre_settings_set_custom_layout_top_left_t)(u16 value);
static vvctre_settings_set_custom_layout_top_left_t vvctre_settings_set_custom_layout_top_left;
typedef void (*vvctre_settings_set_custom_layout_top_top_t)(u16 value);
static vvctre_settings_set_custom_layout_top_top_t vvctre_settings_set_custom_layout_top_top;
typedef void (*vvctre_settings_set_custom_layout_top_right_t)(u16 value);
static vvctre_settings_set_custom_layout_top_right_t vvctre_settings_set_custom_layout_top_right;
typedef void (*vvctre_settings_set_custom_layout_top_bottom_t)(u16 value);
static vvctre_settings_set_custom_layout_top_bottom_t vvctre_settings_set_custom_layout_top_bottom;
typedef void (*vvctre_settings_set_custom_layout_bottom_left_t)(u16 value);
static vvctre_settings_set_custom_layout_bottom_left_t vvctre_settings_set_custom_layout_bottom_left;
typedef void (*vvctre_settings_set_custom_layout_bottom_top_t)(u16 value);
static vvctre_settings_set_custom_layout_bottom_top_t vvctre_settings_set_custom_layout_bottom_top;
typedef void (*vvctre_settings_set_custom_layout_bottom_right_t)(u16 value);
static vvctre_settings_set_custom_layout_bottom_right_t vvctre_settings_set_custom_layout_bottom_right;
typedef void (*vvctre_settings_set_custom_layout_bottom_bottom_t)(u16 value);
static vvctre_settings_set_custom_layout_bottom_bottom_t vvctre_settings_set_custom_layout_bottom_bottom;
typedef void (*vvctre_settings_set_nickname_t)(const char* value);
static vvctre_settings_set_nickname_t vvctre_settings_set_nickname;

VVCTRE_PLUGIN_EXPORT int GetRequiredFunctionCount() {
    return 11;
}

VVCTRE_PLUGIN_EXPORT const char** GetRequiredFunctionNames() {
    return required_function_names;
}
    
VVCTRE_PLUGIN_EXPORT void PluginLoaded(void* core, void* plugin_manager, void* required_functions[]) {
    vvctre_settings_set_resolution = (vvctre_settings_set_resolution_t)required_functions[0];
    vvctre_settings_set_use_custom_layout = (vvctre_settings_set_use_custom_layout_t)required_functions[1];
    vvctre_settings_set_custom_layout_top_left = (vvctre_settings_set_custom_layout_top_left_t)required_functions[2];
    vvctre_settings_set_custom_layout_top_top = (vvctre_settings_set_custom_layout_top_top_t)required_functions[3];
    vvctre_settings_set_custom_layout_top_right = (vvctre_settings_set_custom_layout_top_right_t)required_functions[4];
    vvctre_settings_set_custom_layout_top_bottom = (vvctre_settings_set_custom_layout_top_bottom_t)required_functions[5];
    vvctre_settings_set_custom_layout_bottom_left = (vvctre_settings_set_custom_layout_bottom_left_t)required_functions[6];
    vvctre_settings_set_custom_layout_bottom_top = (vvctre_settings_set_custom_layout_bottom_top_t)required_functions[7];
    vvctre_settings_set_custom_layout_bottom_right = (vvctre_settings_set_custom_layout_bottom_right_t)required_functions[8];
    vvctre_settings_set_custom_layout_bottom_bottom = (vvctre_settings_set_custom_layout_bottom_bottom_t)required_functions[9];
    vvctre_settings_set_nickname = (vvctre_settings_set_nickname_t)required_functions[10];
}


VVCTRE_PLUGIN_EXPORT void InitialSettingsOpening() {
    vvctre_settings_set_resolution(2);
    vvctre_settings_set_use_custom_layout(true);
    vvctre_settings_set_custom_layout_top_left(0);
    vvctre_settings_set_custom_layout_top_top(0);
    vvctre_settings_set_custom_layout_top_right(1000);
    vvctre_settings_set_custom_layout_top_bottom(655);
    vvctre_settings_set_custom_layout_bottom_left(1000);
    vvctre_settings_set_custom_layout_bottom_top(350);
    vvctre_settings_set_custom_layout_bottom_right(1366);
    vvctre_settings_set_custom_layout_bottom_bottom(655);
    vvctre_settings_set_nickname("Aleph");
}
