@echo off

if [%1]==[help] goto :help

set game=lala_beta
set cpc_gfx_mode=1

if [%1]==[justcompile] goto :compile
if [%1]==[clean] goto :clean

cd ..\script
if not exist %game%.spt goto :noscript
echo Compilando script
..\utils\msc3_mk1.exe %game%.spt 30 > nul
copy msc.h ..\dev\my > nul
copy msc-config.h ..\dev\my > nul
copy scripts.bin ..\dev\ > nul
:noscript
cd ..\dev

if [%1]==[justscripts] goto :compile

echo Convirtiendo mapa
..\utils\mapcnv.exe ..\map\mapa.map assets\mapa.h 6 5 15 10 15 packed > nul

echo Convirtiendo enemigos/hotspots
..\utils\ene2h.exe ..\enems\enems.ene assets\enems.h

if [%1]==[nogfx] goto :compile

echo Importando GFX
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=chars in=..\gfx\font.png out=..\bin\font.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=strait2x2 in=..\gfx\work.png out=..\bin\work.bin silent > nul

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites.png out=..\bin\sprites.bin silent > nul

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites_extra.png out=..\bin\sprites_extra.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites_bullet.png out=..\bin\sprites_bullet.bin metasize=1,1 silent > nul

..\utils\png2scr.exe ..\gfx\title.png ..\gfx\title.scr > nul

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=superbuffer in=..\gfx\marco.png out=..\bin\marco.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=superbuffer in=..\gfx\ending.png out=..\bin\ending.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=superbuffer in=..\gfx\title.png out=..\bin\title.bin silent > nul
..\utils\apultra.exe ..\bin\title.bin ..\bin\titlec.bin > nul
..\utils\apultra.exe ..\bin\marco.bin ..\bin\marcoc.bin > nul
..\utils\apultra.exe ..\bin\ending.bin ..\bin\endingc.bin > nul

..\utils\mkts_om.exe platform=cpc cpcmode=%cpc_gfx_mode% pal=..\gfx\pal.png mode=scr in=..\gfx\loading.png out=..\bin\loading.bin silent > nul
..\utils\mkts_om.exe platform=cpc mode=pals in=..\gfx\pal.png prefix=my_inks out=assets\pal.h silent > nul

if [%1]==[justassets] goto :end

:compile
echo Generating LUTs
..\utils\pasmo.exe assets\cpc_TrPixLutM%cpc_gfx_mode%.asm assets\trpixlut.bin
..\utils\apultra.exe assets\trpixlut.bin assets\trpixlutc.bin
..\utils\wyzTrackerParser.exe ..\mus\instrumentos.asm assets\instrumentos.h
echo Compilando guego
zcc +cpc -m -vn -O3 -unsigned -zorg=1024 -lcpcrslib -DCPC_GFX_MODE=%cpc_gfx_mode% -o %game%.bin tilemap_conf.asm mk1.c > nul
..\utils\printsize.exe %game%.bin
..\utils\printsize.exe scripts.bin

echo Construyendo Snapshot %game%.sna
del %game%.sna > nul
..\utils\cpctbin2sna.exe %game%.bin 0x400 -pc 0x400 -o %game%.sna

rem echo Construyendo cinta

if [%1]==[justcompile] goto :end
if [%1]==[noclean] goto :end

:clean
echo Limpiando

goto :end 

:help
echo "compile.bat help|justcompile|clean|justscripts|justassets|nogfx"

:end
echo Hecho!
