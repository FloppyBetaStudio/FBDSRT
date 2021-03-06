// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PermissionCommand {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PERMISSIONCOMMAND
public:
    class PermissionCommand& operator=(class PermissionCommand const&) = delete;
    PermissionCommand(class PermissionCommand const&) = delete;
    PermissionCommand() = delete;
#endif

public:
    /*0*/ virtual ~PermissionCommand();
    /*1*/ virtual void execute(class CommandOrigin const&, class CommandOutput&) const;
    MCAPI static void setup(class CommandRegistry&, class PermissionsFile*);

protected:

private:
    MCAPI void list(class CommandOrigin const&, class CommandOutput&) const;
    MCAPI void reload(class CommandOrigin const&, class CommandOutput&) const;
    MCAPI void set(class CommandOrigin const&, class CommandOutput&) const;
    MCAPI static class PermissionsFile* mPermissionsFile;

};