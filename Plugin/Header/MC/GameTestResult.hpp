// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct GameTestResult {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_GAMETESTRESULT
public:
    GameTestResult() = delete;
#endif

public:
    MCAPI GameTestResult(struct GameTestResult const&);
    MCAPI struct GameTestResult& operator=(struct GameTestResult&&);
    MCAPI struct GameTestResult& operator=(struct GameTestResult const&);
    MCAPI bool operator==(struct GameTestResult const&) const;
    MCAPI ~GameTestResult();

protected:

private:

};