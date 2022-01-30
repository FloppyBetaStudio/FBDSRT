// This Header is auto generated by BDSLiteLoader Toolchain
#pragma once
#define AUTO_GENERATED
#include "../Global.h"
#include "MinecraftEventing.hpp"

#define BEFORE_EXTRA
// Include Headers or Declare Types Here

#undef BEFORE_EXTRA

class PlayerEventCoordinator {

#define AFTER_EXTRA
// Add Member There

#undef AFTER_EXTRA

#ifndef DISABLE_CONSTRUCTOR_PREVENTION_PLAYEREVENTCOORDINATOR
public:
    class PlayerEventCoordinator& operator=(class PlayerEventCoordinator const&) = delete;
    PlayerEventCoordinator(class PlayerEventCoordinator const&) = delete;
    PlayerEventCoordinator() = delete;
#endif

public:
    /*0*/ virtual ~PlayerEventCoordinator();
    MCAPI void registerPlayerGameplayHandler(std::unique_ptr<class PlayerGameplayHandler>&&);
    MCAPI void sendPlayerAddExp(struct PlayerAddExpEvent const&);
    MCAPI void sendPlayerAddLevel(struct PlayerAddLevelEvent const&);
    MCAPI void sendPlayerArmorExchange(struct PlayerArmorExchangeEvent const&);
    MCAPI void sendPlayerAwardAchievement(class Player&, enum MinecraftEventing::AchievementIds);
    MCAPI void sendPlayerCaravanChanged(class Actor const&, int);
    MCAPI void sendPlayerDestroyBlock(struct PlayerDestroyBlockEvent const&);
    MCAPI void sendPlayerDestroyedBlock(class Player&, int, int, int);
    MCAPI void sendPlayerDie(struct PlayerDamageEvent const&);
    MCAPI void sendPlayerDropItem(struct PlayerDropItemEvent const&);
    MCAPI void sendPlayerEatFood(struct PlayerEatFoodEvent const&);
    MCAPI enum CoordinatorResult sendPlayerGetExperienceOrb(struct PlayerGetExperienceOrbEvent const&);
    MCAPI void sendPlayerHurt(struct PlayerDamageEvent const&);
    MCAPI enum CoordinatorResult sendPlayerInteract(struct PlayerInteractEvent const&);
    MCAPI void sendPlayerItemEquipped(class Player&, class ItemInstance const&, int);
    MCAPI void sendPlayerItemPlaceInteraction(class Player&, class ItemInstance const&);
    MCAPI void sendPlayerItemUseInteraction(class Player&, class ItemInstance const&);
    MCAPI void sendPlayerMove(class Player&);
    MCAPI void sendPlayerOpenContainer(struct PlayerOpenContainerEvent const&);
    MCAPI void sendPlayerRespawn(struct PlayerEvent const&);
    MCAPI enum CoordinatorResult sendPlayerSayCommand(struct PlayerSayCommandEvent const&);
    MCAPI void sendPlayerShootArrow(struct PlayerShootArrowEvent const&);
    MCAPI void sendPlayerSlide(class Player&);
    MCAPI void sendPlayerTeleported(class Player&);
    MCAPI void sendPlayerTick(class Player&);
    MCAPI void sendPlayerUpdateInteraction(struct PlayerUpdateInteractionEvent const&);
    MCAPI void sendPlayerUseNameTag(struct PlayerUseNameTagEvent const&);

protected:

private:

};