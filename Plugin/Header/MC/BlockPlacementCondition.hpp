// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockPlacementCondition {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKPLACEMENTCONDITION
public:
    struct BlockPlacementCondition& operator=(struct BlockPlacementCondition const&) = delete;
    BlockPlacementCondition(struct BlockPlacementCondition const&) = delete;
    BlockPlacementCondition() = delete;
#endif

public:
    MCAPI void _addBlockDescriptor(class BlockDescriptor const&);
    MCAPI ~BlockPlacementCondition();

protected:

private:

};