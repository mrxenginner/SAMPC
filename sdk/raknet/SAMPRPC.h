
#ifndef _SAMPRPC_H
#define _SAMPRPC_H

#include <assert.h>

// Warning: If you are planning to add RPC identifiers and register the RPC with REGISTER_STATIC_RPC(),
// UNREGISTER_STATIC_RPC(), REGISTER_CLASS_MEMBER_RPC() or UNREGISTER_CLASS_MEMBER_RPC() function-like macros,
// then the identifier name must be start with "RPC_", if not, the program compilation will fail!
// See the macros in ./NetworkTypes.h

// Note: Unique ID for RPCs must be between 0-255! Exceeding the range will cause integer overflow, and calls other unwanted registered function.
// To change the range, modify UniqueID typedef in ./NetworkTypes.h from "unsigned char" (default data type) to "unsigned short" for 0-65535 range.

//UniqueID


enum
{
	RPC_ServerJoin,
	RPC_ServerQuit,
	RPC_InitGame,
	RPC_VehicleSpawn,
	RPC_VehicleDestroy,
	RPC_VehicleDamage,
	RPC_SetCheckpoint,
	RPC_DisableCheckpoint,
	RPC_SetRaceCheckpoint,
	RPC_DisableRaceCheckpoint,
	RPC_GameModeRestart,
	RPC_ConnectionRejected,
	RPC_ClientMessage,
	RPC_WorldTime,
	RPC_Pickup,
	RPC_DestroyPickup,
	RPC_DestroyWeaponPickup,
	RPC_Weather,
	RPC_Instagib,
	RPC_SetTimeEx,
	RPC_ToggleClock,
	RPC_Chat,
	RPC_RequestClass,
	RPC_RequestSpawn,
	RPC_Spawn,
	RPC_ClientJoin,
	RPC_ServerCommand,
	RPC_SetInteriorId,
	RPC_AdminMapTeleport,
	RPC_VehicleDestroyed,
	RPC_PickedUpWeapon,
	RPC_PickedUpPickup,
	RPC_Death,
	RPC_EnterVehicle,
	RPC_ExitVehicle,
	RPC_UpdateScoresPingsIPs,
	RPC_ScmEvent,
	RPC_MenuSelect,
	RPC_MenuQuit,
	RPC_TypingEvent,
	RPC_ClientCheck,
	RPC_Click,
	RPC_WorldAddActor,
	RPC_WorldRemoveActor,
	RPC_ActorDamage,
	RPC_CreateLabel,
	RPC_DestroyLabel,
	RPC_ChatBubble,
	RPC_VehicleParams,
	RPC_SetTimer,
	RPC_ModelRequest,

	RPC_ScrSetSpawnInfo = 100,
	RPC_ScrSetPlayerTeam,
	RPC_ScrSetPlayerSkin,
	RPC_ScrSetPlayerName,
	RPC_ScrSetPlayerPos,
	RPC_ScrSetPlayerPosFindZ,
	RPC_ScrSetPlayerHealth,
	RPC_ScrPutPlayerInVehicle,
	RPC_ScrRemovePlayerFromVehicle,
	RPC_ScrSetPlayerColor,
	RPC_ScrDisplayGameText,
	RPC_ScrSetInterior,
	RPC_ScrSetCameraPos,
	RPC_ScrSetCameraLookAt,
	RPC_ScrSetVehiclePos,
	RPC_ScrSetVehicleZAngle,
	RPC_ScrVehicleParams,
	RPC_ScrSetCameraBehindPlayer,
	RPC_ScrTogglePlayerControllable,
	RPC_ScrPlaySound,
	RPC_ScrSetWorldBounds,
	RPC_ScrHaveSomeMoney,
	RPC_ScrSetPlayerFacingAngle,
	RPC_ScrResetMoney,
	RPC_ScrResetPlayerWeapons,
	RPC_ScrGivePlayerWeapon,
	RPC_ScrRespawnVehicle,
	RPC_ScrLinkVehicle,
	RPC_ScrSetPlayerArmour,
	RPC_ScrDeathMessage,
	RPC_ScrSetMapIcon,
	RPC_ScrDisableMapIcon,
	RPC_ScrSetWeaponAmmo,
	RPC_ScrSetGravity,
	RPC_ScrSetVehicleHealth,
	RPC_ScrAttachTrailerToVehicle,
	RPC_ScrDetachTrailerFromVehicle,
	RPC_ScrCreateObject,
	RPC_ScrSetObjectPos,
	RPC_ScrSetObjectRotation,
	RPC_ScrDestroyObject,
	RPC_ScrSetPlayerVirtualWorld,
	RPC_ScrSetVehicleVirtualWorld,
	RPC_ScrCreateExplosion,
	RPC_ScrShowNameTag,
	RPC_ScrMoveObject,
	RPC_ScrStopObject,
	RPC_ScrSetObjectScale,
	RPC_ScrNumberPlate,
	RPC_ScrTogglePlayerSpectating,
	RPC_ScrSetPlayerSpectating,
	RPC_ScrPlayerSpectatePlayer,
	RPC_ScrPlayerSpectateVehicle,
	RPC_ScrForceSpawnSelection,
	RPC_ScrRemoveComponent,
	RPC_ScrAttachObjectToPlayer,
	RPC_ScrInitMenu,
	RPC_ScrShowMenu,
	RPC_ScrHideMenu,
	RPC_ScrSetPlayerWantedLevel,
	RPC_ScrShowTextDraw,
	RPC_ScrHideTextDraw,
	RPC_ScrEditTextDraw,
	RPC_ScrAddGangZone,
	RPC_ScrRemoveGangZone,
	RPC_ScrFlashGangZone,
	RPC_ScrStopFlashGangZone,
	RPC_ScrApplyAnimation,
	RPC_ScrClearAnimations,
	RPC_ScrSetSpecialAction,
	RPC_ScrEnableStuntBonus,
	RPC_ScrSetVehicle,
	RPC_ScrSetPlayer,
	RPC_ScrVehicleVelocity,
	RPC_ScrPlayerVelocity,
	RPC_ScrInterpolateCamera,
	RPC_ScrVehicleComponent,
	RPC_ScrSetGameSpeed,
	RPC_ScrToggleChatbox,
	RPC_ScrToggleWidescreen,
	RPC_ScrSetScore,
	RPC_ScrSetShopName,
	RPC_ScrAudioStream,
	RPC_ScrPlayCrimeReport,
	RPC_ScrAttachObjectToCamera,
	RPC_ScrSetActorPos,
	RPC_ScrSetActorFacingAngle,
	RPC_ScrSetActorHealth,
	RPC_ScrApplyActorAnimation,
	RPC_ScrClearActorAnimation,
	RPC_ScrDisableVehicleCollision,
	RPC_ScrClickTextDraw,

	MAX_RPC_UNIQUE_ID, // Don't use it, and leave it as last constant
};

//static_assert((UniqueID)-1 >= MAX_RPC_UNIQUE_ID, "Unique ID limit reached. See the notes in SAMPRPC.h");
static_assert(MAX_RPC_UNIQUE_ID < 256, "Unique ID limit reached.");
#endif // _SAMPRPC_H
