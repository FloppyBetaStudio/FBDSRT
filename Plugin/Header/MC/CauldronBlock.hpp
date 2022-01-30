// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "MinecraftEventing.hpp"
#include "ActorBlock.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class CauldronBlock : public ActorBlock {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_CAULDRONBLOCK
public:
    class CauldronBlock& operator=(class CauldronBlock const&) = delete;
    CauldronBlock(class CauldronBlock const&) = delete;
    CauldronBlock() = delete;
#endif

public:
    /*0*/ virtual ~CauldronBlock();
    /*1*/ virtual bool hasTag(class BlockSource&, class BlockPos const&, class Block const&, std::string const&) const;
    /*2*/ virtual bool isObstructingChests(class BlockSource&, class BlockPos const&) const;
    /*3*/ virtual class Vec3 randomlyModifyPosition(class BlockPos const&) const;
    /*4*/ virtual void addAABBs(class Block const&, class BlockSource&, class BlockPos const&, class AABB const*, std::vector<class AABB>&) const;
    /*5*/ virtual class AABB const& getAABB(class BlockSource const&, class BlockPos const&, class Block const&, class AABB&, bool) const;
    /*6*/ virtual bool addCollisionShapes(class Block const&, class BlockSource&, class BlockPos const&, class AABB const*, std::vector<class AABB>&, class optional_ref<struct IActorMovementProxy>) const;
    /*7*/ virtual void onProjectileHit(class BlockSource&, class BlockPos const&, class Actor const&) const;
    /*8*/ virtual void onLightningHit(class BlockSource&, class BlockPos const&) const;
    /*9*/ virtual bool liquidCanFlowIntoFromDirection(unsigned char, class std::function<class Block const& (class BlockPos const& )> const&, class BlockPos const&) const;
    /*10*/ virtual void __unk_vfn_0();
    /*11*/ virtual bool isStrippable(class Block const&) const;
    /*12*/ virtual class Block const& getStrippedBlock(class Block const&) const;
    /*13*/ virtual bool canProvideSupport(class Block const&, unsigned char, enum BlockSupportType) const;
    /*14*/ virtual class CopperBehavior const* tryGetCopperBehavior() const;
    /*15*/ virtual void __unk_vfn_1();
    /*16*/ virtual void __unk_vfn_2();
    /*17*/ virtual void __unk_vfn_3();
    /*18*/ virtual void __unk_vfn_4();
    /*19*/ virtual void __unk_vfn_5();
    /*20*/ virtual void __unk_vfn_6();
    /*21*/ virtual void __unk_vfn_7();
    /*22*/ virtual void __unk_vfn_8();
    /*23*/ virtual void __unk_vfn_9();
    /*24*/ virtual void __unk_vfn_10();
    /*25*/ virtual bool isDoubleSlabBlock() const;
    /*26*/ virtual void __unk_vfn_11();
    /*27*/ virtual void __unk_vfn_12();
    /*28*/ virtual void __unk_vfn_13();
    /*29*/ virtual void __unk_vfn_14();
    /*30*/ virtual void __unk_vfn_15();
    /*31*/ virtual void __unk_vfn_16();
    /*32*/ virtual bool canBeAscendedByJumping(class Actor const&, class BlockPos const&) const;
    /*33*/ virtual bool isValidAuxValue(int) const;
    /*34*/ virtual bool canFillAtPos(class BlockSource&, class BlockPos const&, class Block const&) const;
    /*35*/ virtual void onFillBlock(class BlockSource&, class BlockPos const&, class Block const&) const;
    /*36*/ virtual int getDirectSignal(class BlockSource&, class BlockPos const&, int) const;
    /*37*/ virtual void __unk_vfn_17();
    /*38*/ virtual void __unk_vfn_18();
    /*39*/ virtual bool canContainLiquid() const;
    /*40*/ virtual bool shouldConnectToRedstone(class BlockSource&, class BlockPos const&, int) const;
    /*41*/ virtual void handlePrecipitation(class BlockSource&, class BlockPos const&, float, float) const;
    /*42*/ virtual float getFlexibility(class BlockSource&, class BlockPos const&) const;
    /*43*/ virtual bool shouldDispense(class BlockSource&, class Container&) const;
    /*44*/ virtual bool dispense(class BlockSource&, class Container&, int, class Vec3 const&, unsigned char) const;
    /*45*/ virtual void transformOnFall(class BlockSource&, class BlockPos const&, class Actor*, float) const;
    /*46*/ virtual void onRedstoneUpdate(class BlockSource&, class BlockPos const&, int, bool) const;
    /*47*/ virtual void onMove(class BlockSource&, class BlockPos const&, class BlockPos const&) const;
    /*48*/ virtual void __unk_vfn_19();
    /*49*/ virtual void movedByPiston(class BlockSource&, class BlockPos const&) const;
    /*50*/ virtual void onStructureBlockPlace(class BlockSource&, class BlockPos const&) const;
    /*51*/ virtual void onStructureNeighborBlockPlace(class BlockSource&, class BlockPos const&) const;
    /*52*/ virtual void setupRedstoneComponent(class BlockSource&, class BlockPos const&) const;
    /*53*/ virtual enum BlockProperty getRedstoneProperty(class BlockSource&, class BlockPos const&) const;
    /*54*/ virtual void __unk_vfn_20();
    /*55*/ virtual bool isFilteredOut(enum BlockRenderLayer) const;
    /*56*/ virtual void __unk_vfn_21();
    /*57*/ virtual bool ignoreEntitiesOnPistonMove(class Block const&) const;
    /*58*/ virtual bool onFertilized(class BlockSource&, class BlockPos const&, class Actor*, enum FertilizerType) const;
    /*59*/ virtual bool mayConsumeFertilizer(class BlockSource&) const;
    /*60*/ virtual bool canBeFertilized(class BlockSource&, class BlockPos const&, class Block const&) const;
    /*61*/ virtual bool mayPick() const;
    /*62*/ virtual bool mayPlace(class BlockSource&, class BlockPos const&, unsigned char) const;
    /*63*/ virtual bool mayPlaceOn(class BlockSource&, class BlockPos const&) const;
    /*64*/ virtual bool tryToTill(class BlockSource&, class BlockPos const&, class Actor&, class ItemStack&) const;
    /*65*/ virtual bool breaksFallingBlocks(class Block const&, class BaseGameVersion) const;
    /*66*/ virtual void destroy(class BlockSource&, class BlockPos const&, class Block const&, class Actor*) const;
    /*67*/ virtual bool getIgnoresDestroyPermissions(class Actor&, class BlockPos const&) const;
    /*68*/ virtual void neighborChanged(class BlockSource&, class BlockPos const&, class BlockPos const&) const;
    /*69*/ virtual bool getSecondPart(class BlockSource const&, class BlockPos const&, class BlockPos&) const;
    /*70*/ virtual int getResourceCount(class Randomize&, class Block const&, int) const;
    /*71*/ virtual class ItemInstance getResourceItem(class Randomize&, class Block const&, int) const;
    /*72*/ virtual class ItemInstance asItemInstance(class BlockSource&, class BlockPos const&, class Block const&) const;
    /*73*/ virtual void __unk_vfn_22();
    /*74*/ virtual class Block const& getPlacementBlock(class Actor&, class BlockPos const&, unsigned char, class Vec3 const&, int) const;
    /*75*/ virtual bool isAttachedTo(class BlockSource&, class BlockPos const&, class BlockPos&) const;
    /*76*/ virtual bool attack(class Player*, class BlockPos const&) const;
    /*77*/ virtual void handleEntityInside(class BlockSource&, class BlockPos const&, class Actor*, class Vec3&) const;
    /*78*/ virtual void entityInside(class BlockSource&, class BlockPos const&, class Actor&) const;
    /*79*/ virtual int getExperienceDrop(class Random&) const;
    /*80*/ virtual void __unk_vfn_23();
    /*81*/ virtual float calcGroundFriction(struct IMobMovementProxy const&, class BlockPos const&) const;
    /*82*/ virtual void __unk_vfn_24();
    /*83*/ virtual void __unk_vfn_25();
    /*84*/ virtual int getComparatorSignal(class BlockSource&, class BlockPos const&, class Block const&, unsigned char) const;
    /*85*/ virtual bool canSpawnAt(class BlockSource const&, class BlockPos const&) const;
    /*86*/ virtual void notifySpawnedAt(class BlockSource&, class BlockPos const&) const;
    /*87*/ virtual void __unk_vfn_26();
    /*88*/ virtual int getIconYOffset() const;
    /*89*/ virtual bool isAuxValueRelevantForPicking() const;
    /*90*/ virtual int getColor(class Block const&) const;
    /*91*/ virtual int getColor(class BlockSource&, class BlockPos const&, class Block const&) const;
    /*92*/ virtual int getColorAtPos(class BlockSource&, class BlockPos const&) const;
    /*93*/ virtual bool isSeasonTinted(class Block const&, class BlockSource&, class BlockPos const&) const;
    /*94*/ virtual class AABB const& getVisualShape(class Block const&, class AABB&, bool) const;
    /*95*/ virtual void __unk_vfn_27();
    /*96*/ virtual class Block const& getRenderBlock() const;
    /*97*/ virtual unsigned char getMappedFace(unsigned char, class Block const&) const;
    /*98*/ virtual enum Flip getFaceFlip(unsigned char, class Block const&) const;
    /*99*/ virtual void animateTick(class BlockSource&, class BlockPos const&, class Random&) const;
    /*100*/ virtual void __unk_vfn_28();
    /*101*/ virtual class ItemInstance getSilkTouchItemInstance(class Block const&) const;
    /*102*/ virtual class Block const* tryLegacyUpgrade(unsigned short) const;
    /*103*/ virtual bool dealsContactDamage(class Actor const&, class Block const&, bool) const;
    /*104*/ virtual class Block const* tryGetInfested(class Block const&) const;
    /*105*/ virtual class Block const* tryGetUninfested(class Block const&) const;
    /*106*/ virtual void onRemove(class BlockSource&, class BlockPos const&) const;
    /*107*/ virtual void onExploded(class BlockSource&, class BlockPos const&, class Actor*) const;
    /*108*/ virtual void onStandOn(class Actor&, class BlockPos const&) const;
    /*109*/ virtual void onStepOn(class Actor&, class BlockPos const&) const;
    /*110*/ virtual void __unk_vfn_29();
    /*111*/ virtual void __unk_vfn_30();
    /*112*/ virtual void onPlace(class BlockSource&, class BlockPos const&) const;
    /*113*/ virtual void tick(class BlockSource&, class BlockPos const&, class Random&) const;
    /*114*/ virtual void __unk_vfn_31();
    /*115*/ virtual bool use(class Player&, class BlockPos const&, unsigned char) const;
    /*116*/ virtual bool canSurvive(class BlockSource&, class BlockPos const&) const;
    /*117*/ virtual int getExtraRenderLayers() const;
    /*118*/ virtual class mce::Color getMapColor(class BlockSource&, class BlockPos const&) const;
    /*119*/ virtual void __unk_vfn_32();
    /*120*/ virtual void __unk_vfn_33();
    /*
    inline bool isInteractiveBlock() const{
        bool (CauldronBlock::*rv)() const;
        *((void**)&rv) = dlsym("?isInteractiveBlock@CauldronBlock@@UEBA_NXZ");
        return (this->*rv)();
    }
    inline bool hasComparatorSignal() const{
        bool (CauldronBlock::*rv)() const;
        *((void**)&rv) = dlsym("?hasComparatorSignal@CauldronBlock@@UEBA_NXZ");
        return (this->*rv)();
    }
    */
    MCAPI CauldronBlock(std::string const&, int);
    MCAPI int getLiquidLevel(int) const;
    MCAPI void setLiquidLevel(class BlockSource&, class BlockPos const&, int, enum CauldronLiquidType) const;
    MCAPI static bool canReceiveStalactiteDrip(class BlockSource&, class BlockPos const&, enum MaterialType);
    MCAPI static void spawnPotionParticles(class Level&, class Vec3 const&, class Random&, int, int);

protected:

private:
    MCAPI void _explodeCauldronContents(class BlockSource&, class BlockPos const&, unsigned short) const;
    MCAPI bool const _mayUpdateLiquidLevel(class BlockSource&, class BlockPos const&) const;
    MCAPI void _sendCauldronUsedEventToClient(class Player const&, short, enum MinecraftEventing::POIBlockInteractionType) const;
    MCAPI void _spawnCauldronEvent(class BlockSource&, class BlockPos const&, enum LevelEvent) const;
    MCAPI void _useInventory(class Player&, class ItemStack&, class ItemStack&, int) const;
    MCAPI static int const BASE_WATER_PIXEL;
    MCAPI static class BaseGameVersion const CAULDRON_DOESNT_BREAK_FALLING_BLOCK_VERSION;
    MCAPI static int const PIXEL_PER_LEVEL;

};