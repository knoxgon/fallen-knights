#pragma once

namespace NS_PlayerAttributes {
	enum class Class {
		Warrior = 1,
		Rogue,
		Mage,
		Priest
	};
	enum class Nation {
		El_morad = 1,
		Karus
	};
}

namespace NS_Monsters {
	enum class Moradon_Monsters {
		BANDICOOT = 1,
		BATTALION,
		BLOOD_WORM,
		BULCAN,
		DARK_EYES,
		DIRE_WOLF,
		GAVOLT,
		GIANT_BULCAN,
		GLOOMWING,
		GLYPTODON,
		KECOON,
		KECOON_CAPTAIN,
		KECOON_WARRIOR,
		KEILAN,
		LYCAN,
		ORC_WATCHER,
		PARALYZER,
		PINCER,
		ROTTEN_EYES,
		SABERTOOTH,
		SCAVENGER_BANDICOOT,
		SCORPION,
		SKELETON,
		SMILODON,
		SPOILER,
		UNDYING,
		WEREWOLF,
		WILD_BULCAN,
		WILD_SMILODON
	};
	enum class LC_EM_Monsters {
		ANCIENT = 1,
		APE,
		APOSTLE,
		ASH_KNIGHT,
		BARON,
		BATTALION,
		BLOODON,
		BURNING_STONE,
		CARDINAL,
		CENTAUR,
		DEATH_KNIGHT,
		DECAYED_ZOMBIE,
		DERUVISH,
		DRAGON_TOOTH_COMMANDER,
		DRAGON_TOOTH_KNIGHT,
		DRAGON_TOOTH_SOLDIER,
		DUST_ORC,
		FLAME_ROCK,
		GARUNA,
		GIANT_GOLEM,
		HARPY,
		HAUNGA,
		HAUNGA_WARRIOR,
		HELL_HOUND,
		HORNET,
		LARD_ORC,
		LICH,
		MACHIRODUS,
		MANTICORE,
		RAVEN_HARPY,
		SKELETON_CHAMPION,
		SKELETON_KNIGHT,
		SKELETON_WARRIOR,
		STONE_GOLEM,
		TREANT,
		TROLL,
		TROLL_WARRIOR,
		URUK_BLADE,
		URUK_HAI,
		URUK_TRON
	};
	enum class Eslant_Monsters {
		ASTAROTH = 1,
		BALROG,
		BRAHMAN,
		CRIMSON_WING,
		DARK_KNIGHT,
		DARK_STONE,
		DARKMARE,
		DEATH_WIZARD,
		DOOM_KNIGHT,
		DOOM_SOLDIER,
		DREADMARE,
		EVIL_WIZARD,
		FALCON,
		FIERCE_RED_DRAGON,
		GARGOYLE,
		GRENDEL,
		PARAMUN,
		PRICILLA,
		SATIROS,
		TITAN,
		TROLL_CAPTAIN
	};
	enum class Bifrost_Monsters {
		ASHITON = 1,
		EGO,
		ENVY,
		GLUTTON,
		GREED,
		LUST,
		SLOTH,
		WRATCH
	};
	enum class HellAbyss_Monsters{
		REPTILE_HOUND = 1,
		KWARZ,
		LUTTERSLAN,
		WRAITH
	};
	enum class FelankorsLair_Monsters {
		DRAGON_SERVANT = 1,
		FELANKOR,
		GUARDIAN_OF_FELANKOR
	};
	enum class RonarkLand_Monsters {
		APOSTLE_OF_FLAME = 1,
		APOSTLE_OF_PIERCING_COLD,
		DREADIUM_FOSSIL_OF_DRAGON,
		FOSSIL_GUARD,
		HAVOC,
		KERAMASH,
		LYOT,
		NAGMASH
	};
	enum class Delos_Monsters {
		BLACK_WIDOW = 1,
		BURNING_SKELETON,
		CAVE_LEECH,
		FALLEN_ANGEL,
		GHOST_WARRIOR,
		PHANTOM,
		REAPER,
		SHADOW
	};
	enum class JuradMountain_Monsters {
		JURADIN = 1,
		SERVANT_OF_JURADIN,
		MESSENGER_OF_JURADIN
	};
	enum class Krowaz_Monsters {
		KROWAZ = 1,
		WIRINIOM,
		BAAL,
		DEFENDER_OF_KROWAZ,
		BALTAZAR,
		SPIDER
	};
	enum class Forgotten_Temple {
		VANE = 1,
		RON,
		TEMPLE_GUARDIAN,
		ENION,
		ERENION,
		HANGUK
	};
}

namespace NS_WeaponNames {
	enum class Weapon_Name {
		DAGGER_SHARD = 1,
		DAGGER_CLEAVER,
		DAGGER_KUKRY,
		DAGGER_SWORD_BREAKER,
		DAGGER_ASSASSIN_DAGGER,
		DAGGER_STILETTO,
		DAGGER_MAIL_BREAKER,
		DAGGER_KNIFE,
		DAGGER_DIRK,
		DAGGER_FINE_DAGGER,
		DAGGER_DAGGER,
		ONE_HANDED_AXE_DEEP_SCAR,
		ONE_HANDED_AXE_TOMAHAWK,
		ONE_HANDED_AXE_WRIST_CUTTER,
		ONE_HANDED_AXE_CLEAVER_AXE,
		ONE_HANDED_AXE_MILITARY_PICK,
		ONE_HANDED_AXE_WARRIOR_AXE,
		ONE_HANDED_AXE_LARGE_AXE,
		ONE_HANDED_AXE_DOUBLE_AXE,
		ONE_HANDED_AXE_WOOD_CUTTER,
		ONE_HANDED_AXE_HAND_AXE,
		ONE_HANDED_AXE_STONE_AXE,
		TWO_HANDED_AXE_BATTLE_AXE,
		TWO_HANDED_AXE_WAR_AXE,
		TWO_HANDED_AXE_LUMBER_AXE,
		TWO_HANDED_AXE_TIMBER_AXE,
		TWO_HANDED_AXE_TABAR,
		TWO_HANDED_AXE_TWIN_AXE,
		TWO_HANDED_AXE_GREAT_AXE,
		TWO_HANDED_AXE_BROAD_AXE,
		TWO_HANDED_AXE_BONE_AXE,
		TWO_HANDED_AXE_BONE_CLEAVER,
		RARE_TWO_HANDED_AXE_UNDEFEATABLE_BAAL,
		RARE_TWO_HANDED_AXE_JURADINS_AXE,
		RARE_TWO_HANDED_AXE_AVEDON,
		RARE_TWO_HANDED_AXE_GIGANTIC_AXE,
		RARE_TWO_HANDED_AXE_BLADE_AXE,
		RARE_TWO_HANDED_AXE_JAVANA_AXE,
		ONE_HANDED_SPEAR_LONG_SCHYTE,
		ONE_HANDED_SPEAR_HARPON_SPEAR,
		TWO_HANDED_SPEAR_RAPTOR,
		TWO_HANDED_SPEAR_GLAVE,
		TWO_HANDED_SPEAR_BARDISH,
		TWO_HANDED_SPEAR_HALBERD,
		TWO_HANDED_SPEAR_BILL,
		TWO_HANDED_SPEAR_HARSH_SCHYTE,
		TWO_HANDED_SPEAR_POLE_AXE,
		RARE_TWO_HANDED_SPEAR_JURADINS_SPEAR,
		TWO_HANDED_CLUB_IRON_IMPACT,
		TWO_HANDED_CLUB_TOTAMIC_CLUB,
		TWO_HANDED_CLUB_LARGE_BREAKER,
		TWO_HANDED_CLUB_GIANT_MAUL,
		RARE_TWO_HANDED_CLUB_HELL_BREAKER,
		RARE_TWO_HANDED_CLUB_JURADINS_VERDICT,
		ONE_HANDED_CLUB_PRIEST_MORNING_STAR,
		ONE_HANDED_CLUB_IRON_STAR,
		ONE_HANDED_CLUB_SPIKED_CLUB,
		ONE_HANDED_CLUB_PRIEST_BREAKER,
		ONE_HANDED_CLUB_CRACKER,
		RARE_ONE_HANDED_CLUB_UNDEFEATABLE_LEONARD,
		RARE_ONE_HANDED_CLUB_SMITE_HAMMER,
		RARE_ONE_HANDED_CLUB_STONE_SPLITTER,
		RARE_ONE_HANDED_CLUB_DRAGON_TOOTH_HAMMER,
		RARE_ONE_HANDED_CLUB_LYCAON_HAMMER,
		RARE_ONE_HANDED_CLUB_LUPUS_HAMMER,
		RARE_ONE_HANDED_CLUB_LOBO_HAMMER,
		RARE_ONE_HANDED_CLUB_SKULL_HAMMER,
		ONE_HANDED_SWORD_SHORT_BLADE,
		ONE_HANDED_SWORD_FLAME_SWORD,
		ONE_HANDED_SWORD_SLAYER,
		ONE_HANDED_SWORD_RAPIER,
		ONE_HANDED_SWORD_SABRE,
		ONE_HANDED_SWORD_FALCHION,
		RARE_ONE_HANDED_SWORD_JURADINS_SAPPHIRE,
		RARE_ONE_HANDED_SWORD_HANGUK_SWORD,
		TWO_HANDED_SWORD_MIRAGE,
		TWO_HANDED_SWORD_DESTROYER,
		TWO_HANDED_SWORD_FLAMBERGE,
		TWO_HANDED_SWORD_CLAYMORE,
		TWO_HANDED_SWORD_WAR_SWORD,
		TWO_HANDED_SWORD_DURANDAL,
		RARE_TWO_HANDED_SWORD_JURADINS_WRATH,
		RARE_TWO_HANDED_SWORD_UNDEFEATABLE_WIRINIOM,
		RARE_DAGGER_JURADINS_SERVANT_DAGGER,
		RARE_DAGGER_UNDEFEATABLE_RAUM,
		RARE_DAGGER_SHERION,
		RARE_DAGGER_DARK_VANE,
		RARE_DAGGER_COLD__HEARTED_DAGGER
	};
}

namespace NS_ArmorNames {
	enum class Armor_Name {
		FULL_PLATE_ARMOR_HELMET = 1,
		FULL_PLATE_ARMOR_PAULDRON,
		FULL_PLATE_ARMOR_PADS,
		FULL_PLATE_ARMOR_GAUNTLETS,
		FULL_PLATE_ARMOR_BOOTS,
		TAILOR_ARMOR_HELMET,
		TAILOR_ARMOR_PAULDRON,
		TAILOR_ARMOR_PADS,
		TAILOR_ARMOR_GAUNTLETS,
		TAILOR_ARMOR_BOOTS,
		CHITIN_HELMET,
		CHITIN_PAULDRON,
		CHITIN_PADS,
		CHITIN_GAUNTLETS,
		CHITIN_BOOTS,
		CHITIN_SHELL_HELMET,
		CHITIN_SHELL_PAULDRON,
		CHITIN_SHELL_PADS,
		CHITIN_SHELL_GAUNTLETS,
		CHITIN_SHELL_BOOTS,
		RARE_ARMOR_JURADINS_RAGE_HELMET,
		RARE_ARMOR_JURADINS_RAGE_PAULDRON,
		RARE_ARMOR_JURADINS_RAGE_PADS,
		RARE_ARMOR_JURADINS_RAGE_GAUNTLETS,
		RARE_ARMOR_JURADINS_RAGE_BOOTS,
		RARE_ARMOR_KROWAZ_HELMET,
		RARE_ARMOR_KROWAZ_PAULDRON,
		RARE_ARMOR_KROWAZ_PADS,
		RARE_ARMOR_KROWAZ_GAUNTLETS,
		RARE_ARMOR_KROWAZ_BOOTS,
		RARE_SHIELD_JURADINS_DEFENDER,
		RARE_SHIELD_DREAD_SHIELD,
		RARE_SHIELD_DEFENDER_OF_THE_LORD,
		RARE_SHIELD_CHITIN_SHIELD,
		RARE_SHIELD_GABS_BLESSING,
		RARE_SHIELD_SCORPION_SHIELD,
		SHIELD_PLATE_SHIELD,
		SHIELD_OCTAGON_SHIELD,
		SHIELD_WOODEN_SHIELD
	};
}

namespace NS_AccessoryNames {
	enum class Accessory_Name {
		BOSS_BELT_SKELETON_BELT = 1,
		BOSS_BELT_GLASS_BELT,
		BOSS_BELT_ELF_BELT,
		BOSS_BELT_HARPYS_BELT,
		BOSS_BELT_STRING_OF_SKULLS,
		BOSS_BELT_SASH_OF_SORROWS,
		BOSS_BELT_KEKURI_BELT,
		BOSS_BELT_ICE_BELT,
		BOSS_BELT_JUDICIOUS_BELT,
		BOSS_PENDANT_AMULET_OF_CURSE,
		BOSS_PENDANT_CRYSTAL_NECKLACE,
		BOSS_PENDANT_LYCAON_PENDANT,
		BOSS_PENDANT_LOBO_PENDANT,
		BOSS_PENDANT_LUPUS_PENDANT,
		BOSS_EARRING_AGATE_EARRING,
		BOSS_EARRING_ELF_METAL_EARRING,
		BOSS_EARRING_MINOTAURS_EARRING,
		BOSS_EARRING_LILLIMES_EARRING,
		BOSS_RING_RING_OF_THE_FELANKOR,
		BOSS_RING_FOVERING,
		BOSS_RING_LEGIONNAIRE_BAND,
		BOSS_RING_ARARAT_RING,
		BOSS_RING_SHIO_TEARS,
		BOSS_RING_IMIR_RING,
		BOSS_RING_HEROS_VALOR
	};
}

namespace NS_GearAttributes {
	enum class Rarity {
		LOW = 1,
		MEDIUM,
		HIGH,
		UNIQUE_ITEM,
		JURADIN_ITEM,
		PREMIUM_ITEM
	};
	enum class WeaponClass {
		ONE_HANDED = 1,
		TWO_HANDED
	};
	enum class WeaponType {
		SWORD = 1,
		AXE,
		CLUB,
		SPEAR,
		DAGGER
	};
	enum class ArmorType {
		HELMET = 1,
		PAULDRON,
		PADS,
		GAUNTLETS,
		BOOTS,
		SHIELD
	};
	enum class AccessoryType {
		PENDANT = 1,
		EARRING,
		RING,
		BELT
	};
}
