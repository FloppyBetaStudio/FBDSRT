// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Packet.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PositionTrackingDBClientRequestPacket : public Packet {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_POSITIONTRACKINGDBCLIENTREQUESTPACKET
public:
    class PositionTrackingDBClientRequestPacket& operator=(class PositionTrackingDBClientRequestPacket const&) = delete;
    PositionTrackingDBClientRequestPacket(class PositionTrackingDBClientRequestPacket const&) = delete;
#endif

public:
    /*0*/ virtual ~PositionTrackingDBClientRequestPacket();
    /*1*/ virtual enum MinecraftPacketIds getId() const;
    /*2*/ virtual std::string getName() const;
    /*3*/ virtual void write(class BinaryStream&) const;
    /*4*/ virtual bool disallowBatching() const;
    /*5*/ virtual enum StreamReadResult _read(class ReadOnlyBinaryStream&);
    /*
    inline  ~PositionTrackingDBClientRequestPacket(){
         (PositionTrackingDBClientRequestPacket::*rv)();
        *((void**)&rv) = dlsym("??1PositionTrackingDBClientRequestPacket@@UEAA@XZ");
        return (this->*rv)();
    }
    */
    MCAPI PositionTrackingDBClientRequestPacket();

protected:

private:

};