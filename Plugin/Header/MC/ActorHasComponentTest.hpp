// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "FilterTest.hpp"
#include "Json.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ActorHasComponentTest : public FilterTest {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_ACTORHASCOMPONENTTEST
public:
    class ActorHasComponentTest& operator=(class ActorHasComponentTest const&) = delete;
    ActorHasComponentTest(class ActorHasComponentTest const&) = delete;
    ActorHasComponentTest() = delete;
#endif

public:
    /*0*/ virtual ~ActorHasComponentTest();
    /*1*/ virtual bool evaluate(struct FilterContext const&) const;
    /*2*/ virtual void finalizeParsedValue(class IWorldRegistriesProvider&);
    /*3*/ virtual class gsl::basic_string_span<char const, -1> getName() const;
    /*
    inline  ~ActorHasComponentTest(){
         (ActorHasComponentTest::*rv)();
        *((void**)&rv) = dlsym("??1ActorHasComponentTest@@UEAA@XZ");
        return (this->*rv)();
    }
    */

protected:

private:

};