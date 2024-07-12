#include <wups.h>
#include <mocha/mocha.h>

/**
    Mandatory plugin information.
    If not set correctly, the loader will refuse to use the plugin.
**/
WUPS_PLUGIN_NAME("DLP Patcher");
WUPS_PLUGIN_DESCRIPTION("Patches for Download Play");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("DaniElectra");
WUPS_PLUGIN_LICENSE("MIT");

/**
    Gets called ONCE when the plugin was loaded.
**/
INITIALIZE_PLUGIN() {
    if(Mocha_InitLibrary() != MOCHA_RESULT_SUCCESS)
        return;

    // Patch DLP region check by replacing result code with success
    Mocha_IOSUKernelWrite32(0x1239DA7C, 0);

    Mocha_DeInitLibrary();
}
