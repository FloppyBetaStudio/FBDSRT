// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PropertyGroupManager {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PROPERTYGROUPMANAGER
public:
    class PropertyGroupManager& operator=(class PropertyGroupManager const&) = delete;
    PropertyGroupManager(class PropertyGroupManager const&) = delete;
#endif

public:
    MCAPI PropertyGroupManager();
    MCAPI class PropertyGroup const* getPropertyGroup(class HashedString const&) const;
    MCAPI void registerGroup(class HashedString const&, class PropertyGroup const&);
    MCAPI ~PropertyGroupManager();

protected:

private:

};