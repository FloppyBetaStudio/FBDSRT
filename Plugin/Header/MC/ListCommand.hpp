// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ListCommand {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_LISTCOMMAND
public:
    class ListCommand& operator=(class ListCommand const&) = delete;
    ListCommand(class ListCommand const&) = delete;
    ListCommand() = delete;
#endif

public:
    /*0*/ virtual ~ListCommand();
    /*1*/ virtual void execute(class CommandOrigin const&, class CommandOutput&) const;
    MCAPI static void setup(class CommandRegistry&);

protected:

private:

};