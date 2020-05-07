// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

// mk1.c
//#define DEBUG_KEYS
#include <spritepack.h>

// We are using some stuff from splib2 directly.
#asm
		LIB SPMoveSprAbs
		LIB SPPrintAtInv
		LIB SPTileArray
		LIB SPInvalidate
		LIB SPCompDListAddr
#endasm

#include "my/config.h"
#include "prototypes.h"

// DON'T touch these
#define FIXBITS 		6	
#define MAX_ENEMS 		3			

#define BASE_SPRITES 	0xE000 + 0x600
#define BASE_LUT		0xF800 + 0x600
#define BASE_SUPERBUFF  0x9000

// Configure number of blocks and reserve a pool for sprites

#ifdef PLAYER_CAN_FIRE
	#ifdef ENABLE_SIMPLE_COCOS
		#define MAX_PROJECTILES (MAX_BULLETS + MAX_ENEMS)
	#else
		#define MAX_PROJECTILES MAX_BULLETS
	#endif
#else
	#ifdef ENABLE_SIMPLE_COCOS
		#define MAX_PROJECTILES MAX_ENEMS
	#else
		#define MAX_PROJECTILES 0
	#endif
#endif

#define NUMBLOCKS (40 + (MAX_PROJECTILES * 5))

unsigned char AD_FREE [NUMBLOCKS * 15];

// Cosas del juego:

#include "definitions.h"

#ifdef ACTIVATE_SCRIPTING
	#include "my/msc-config.h"
#endif

#ifdef MODE_128K
	#include "128k.h"
	#include "assets/ay_fx_numbers.h"
	#include "assets/librarian.h"
#endif

#include "aplib.h"
#include "pantallas.h"
#include "assets/pal.h"

#ifdef COMPRESSED_LEVELS
	#include "assets/levels.h"
	#include "assets/extrasprites.h"
	#include "my/levelset.h"
#else
	#include "assets/mapa.h"
	#include "assets/tileset.h"
	#include "assets/enems.h"
	#include "assets/sprites.h"
	#include "assets/extrasprites.h"
#endif

#include "my/ci/extra_vars.h"

#include "printer.h"
#include "my/ci/extra_functions.h"

#ifdef ACTIVATE_SCRIPTING
	#ifdef ENABLE_EXTERN_CODE
		#include "my/extern.h"
	#endif
	#include "my/msc.h"
#endif

#include "engine/general.h"
#ifdef BREAKABLE_WALLS
	#include "engine/breakable.h"
#endif
#ifdef PLAYER_CAN_FIRE
	#include "engine/bullets.h"
#endif
#ifdef ENABLE_SIMPLE_COCOS
	#include "engine/simple_cocos.h"
#endif
#ifdef COMPRESSED_LEVELS
	#include "engine/c_levels.h"
#endif
#include "engine.h"
#include "engine/player.h"
#include "engine/enengine.h"
#include "engine/hotspots.h"

#ifdef ENABLE_CHECKPOINTS
	#include "savegame.h"
#endif

#include "mainloop.h"

#ifndef MODE_128K
	// From beepola. Phaser engine by Shiru.
	#include "music.h"
#endif
