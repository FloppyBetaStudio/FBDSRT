// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ResourcePacksInfoPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_RESOURCEPACKSINFOPACKET
public:
    class ResourcePacksInfoPacket& operator=(class ResourcePacksInfoPacket const&) = delete;
    ResourcePacksInfoPacket(class ResourcePacksInfoPacket const&) = delete;
#endif

public:
    /*0*/ virtual ~ResourcePacksInfoPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    /*
    inline  ~ResourcePacksInfoPacket(){
         (ResourcePacksInfoPacket::*rv)();
        *((void**)&rv) = dlsym("??1ResourcePacksInfoPacket@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI ResourcePacksInfoPacket();
    MCAPI ResourcePacksInfoPacket(bool, std::vector<struct PackInfoData>&, std::vector<struct PackInfoData>&, bool);

protected:

private:

};