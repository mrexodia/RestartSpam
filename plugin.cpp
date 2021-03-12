#include "plugin.h"

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registercommand(pluginHandle, "restartspam", [](int argc, char* argv[])
    {
        char mod[MAX_PATH] = "";
        Script::Module::GetMainModulePath(mod);
        dprintf("Spamming '%s'\n", mod);
        char cmd[1024] = "";
        sprintf(cmd, "init \"%s\"", mod);
        for (int i = 0; i < 500; i++)
            DbgCmdExec(cmd);
        return true;
    }, true);
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here.
void pluginStop()
{
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
