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

#define ARM_NOP 0xE320F000 // nop

/**
    Gets called ONCE when the plugin was loaded.
**/
INITIALIZE_PLUGIN() {
    if(Mocha_InitLibrary() != MOCHA_RESULT_SUCCESS)
        return;

    // Patch OTP security level check on DLP to ignore failure due to missing 3DS system updates archive
    Mocha_IOSUKernelWrite32(0x1239E108, ARM_NOP);
    Mocha_IOSUKernelWrite32(0x1239E10C, ARM_NOP);
    Mocha_IOSUKernelWrite32(0x1239E110, ARM_NOP);

    Mocha_DeInitLibrary();
}
