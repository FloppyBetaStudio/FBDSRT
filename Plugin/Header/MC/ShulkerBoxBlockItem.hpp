// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "Json.hpp"
#include "BlockItem.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class ShulkerBoxBlockItem : public BlockItem {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_SHULKERBOXBLOCKITEM
public:
    class ShulkerBoxBlockItem& operator=(class ShulkerBoxBlockItem const&) = delete;
    ShulkerBoxBlockItem(class ShulkerBoxBlockItem const&) = delete;
    ShulkerBoxBlockItem() = delete;
#endif

public:
    /*0*/ virtual ~ShulkerBoxBlockItem();
    /*1*/ virtual void tearDown();
    /*2*/ virtual int getMaxUseDuration(class ItemStack const*) const;
    /*3*/ virtual void __unk_vfn_0();
    /*4*/ virtual void __unk_vfn_1();
    /*5*/ virtual void executeEvent(class ItemStackBase&, std::string const&, class RenderParams&) const;
    /*6*/ virtual void __unk_vfn_2();
    /*7*/ virtual bool isArmor() const;
    /*8*/ virtual bool isBlockPlanterItem() const;
    /*9*/ virtual void __unk_vfn_3();
    /*10*/ virtual void __unk_vfn_4();
    /*11*/ virtual bool isDyeable() const;
    /*12*/ virtual bool isDye() const;
    /*13*/ virtual enum ItemColor getItemColor() const;
    /*14*/ virtual bool isFertilizer() const;
    /*15*/ virtual void __unk_vfn_5();
    /*16*/ virtual bool isThrowable() const;
    /*17*/ virtual bool isUseable() const;
    /*18*/ virtual class ItemComponent* getComponent(class HashedString const&) const;
    /*19*/ virtual class FuelItemComponent* getFuel() const;
    /*20*/ virtual enum BlockShape getBlockShape() const;
    /*21*/ virtual bool canDestroySpecial(class Block const&) const;
    /*22*/ virtual int getLevelDataForAuxValue(int) const;
    /*23*/ virtual short getMaxDamage() const;
    /*24*/ virtual int getAttackDamage() const;
    /*25*/ virtual bool isGlint(class ItemStackBase const&) const;
    /*26*/ virtual void __unk_vfn_6();
    /*27*/ virtual int getPatternIndex() const;
    /*28*/ virtual void __unk_vfn_7();
    /*29*/ virtual bool isWearableThroughLootTable(class CompoundTag const*) const;
    /*30*/ virtual bool canDestroyInCreative() const;
    /*31*/ virtual bool isLiquidClipItem(int) const;
    /*32*/ virtual bool shouldInteractionWithBlockBypassLiquid(class Block const&) const;
    /*33*/ virtual bool requiresInteract() const;
    /*34*/ virtual void appendFormattedHovertext(class ItemStackBase const&, class Level&, std::string&, bool) const;
    /*35*/ virtual bool isValidRepairItem(class ItemStackBase const&, class ItemStackBase const&, class BaseGameVersion const&) const;
    /*36*/ virtual int getEnchantSlot() const;
    /*37*/ virtual int getEnchantValue() const;
    /*38*/ virtual int getArmorValue() const;
    /*39*/ virtual void __unk_vfn_8();
    /*40*/ virtual float getViewDamping() const;
    /*41*/ virtual void __unk_vfn_9();
    /*42*/ virtual void __unk_vfn_10();
    /*43*/ virtual void __unk_vfn_11();
    /*44*/ virtual class mce::Color getColor(class CompoundTag const*, class ItemDescriptor const&) const;
    /*45*/ virtual bool hasCustomColor(class CompoundTag const*) const;
    /*46*/ virtual void __unk_vfn_12();
    /*47*/ virtual void clearColor(class ItemStackBase&) const;
    /*48*/ virtual void clearColor(class CompoundTag*) const;
    /*49*/ virtual void setColor(class ItemStackBase&, class mce::Color const&) const;
    /*50*/ virtual void __unk_vfn_13();
    /*51*/ virtual void __unk_vfn_14();
    /*52*/ virtual void __unk_vfn_15();
    /*53*/ virtual void __unk_vfn_16();
    /*54*/ virtual bool canUseOnSimTick() const;
    /*55*/ virtual float getDestroySpeed(class ItemStackBase const&, class Block const&) const;
    /*56*/ virtual void hitActor(class ItemStack&, class Actor&, class Mob&) const;
    /*57*/ virtual void hitBlock(class ItemStack&, class Block const&, class BlockPos const&, class Mob&) const;
    /*58*/ virtual bool mineBlock(class ItemInstance&, class Block const&, int, int, int, class Actor*) const;
    /*59*/ virtual bool mineBlock(class ItemStack&, class Block const&, int, int, int, class Actor*) const;
    /*60*/ virtual void __unk_vfn_17();
    /*61*/ virtual std::string buildDescriptionId(class ItemDescriptor const&, class CompoundTag const*) const;
    /*62*/ virtual std::string buildEffectDescriptionName(class ItemStackBase const&) const;
    /*63*/ virtual unsigned char getMaxStackSize(class ItemDescriptor const&) const;
    /*64*/ virtual bool inventoryTick(class ItemStack&, class Level&, class Actor&, int, bool) const;
    /*65*/ virtual void refreshedInContainer(class ItemStackBase const&, class Level&) const;
    /*66*/ virtual void fixupCommon(class ItemStackBase&, class Level&) const;
    /*67*/ virtual void __unk_vfn_18();
    /*68*/ virtual void __unk_vfn_19();
    /*69*/ virtual bool validFishInteraction(int) const;
    /*70*/ virtual std::string getInteractText(class Player const&) const;
    /*71*/ virtual int getAnimationFrameFor(class Mob*, bool, class ItemStack const*, bool) const;
    /*72*/ virtual bool canBeCharged() const;
    /*73*/ virtual void playSoundIncrementally(class ItemStack const&, class Mob&) const;
    /*74*/ virtual void __unk_vfn_20();
    /*75*/ virtual std::string getAuxValuesDescription() const;

protected:

private:
    MCAPI std::string buildContainedItemList(class CompoundTag const*) const;

};