// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

struct BlockComponentGroupDescription {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_BLOCKCOMPONENTGROUPDESCRIPTION
public:
    struct BlockComponentGroupDescription& operator=(struct BlockComponentGroupDescription const&) = delete;
#endif

public:
    MCAPI BlockComponentGroupDescription(struct BlockComponentGroupDescription&&);
    MCAPI BlockComponentGroupDescription(struct BlockComponentGroupDescription const&);
    MCAPI BlockComponentGroupDescription();
    MCAPI void foreachDescription(class std::function<void (struct BlockComponentDescription const& )>) const;
    MCAPI struct BlockComponentDescription* getComponentDescription(std::string const&) const;
    MCAPI ~BlockComponentGroupDescription();

protected:

private:

};