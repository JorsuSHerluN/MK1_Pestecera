@echo off

if [%1]==[help] goto :help

set game=lala_beta

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

echo Importando GFX
..\utils\mkts_om.exe platform=cpc cpcmode=1 pal=..\gfx\pal.png mode=chars in=..\gfx\font.png out=..\bin\font.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=1 pal=..\gfx\pal.png mode=strait2x2 in=..\gfx\work.png out=..\bin\work.bin silent > nul

..\utils\mkts_om.exe platform=cpc cpcmode=1 pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites.png out=..\bin\sprites.bin silent > nul

..\utils\mkts_om.exe platform=cpc cpcmode=1 pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites_extra.png out=..\bin\sprites_extra.bin silent > nul
..\utils\mkts_om.exe platform=cpc cpcmode=1 pal=..\gfx\pal.png mode=sprites in=..\gfx\sprites_bullet.png out=..\bin\sprites_bullet.bin metasize=1,1 silent > nul

..\utils\png2scr.exe ..\gfx\title.png ..\gfx\title.scr > nul
..\utils\png2scr.exe ..\gfx\marco.png ..\gfx\marco.scr > nul
..\utils\png2scr.exe ..\gfx\ending.png ..\gfx\ending.scr > nul
..\utils\png2scr.exe ..\gfx\loading.png loading.bin > nul
..\utils\apultra.exe ..\gfx\title.scr title.bin > nul
..\utils\apultra.exe ..\gfx\marco.scr marco.bin > nul
..\utils\apultra.exe ..\gfx\ending.scr ending.bin > nul

if [%1]==[justassets] goto :end

:compile
echo Compilando guego
zcc +zx -vn mk1.c -o %game%.bin -lsplib2_mk2.lib -zorg=24000 > nul
..\utils\printsize.exe %game%.bin
..\utils\printsize.exe scripts.bin

echo Construyendo cinta
rem cambia LOADER por el nombre que quieres que salga en Program:
..\utils\bas2tap -a10 -sLOADER loader\loader.bas loader.tap > nul
..\utils\bin2tap -o screen.tap -a 16384 loading.bin > nul
..\utils\bin2tap -o main.tap -a 24000 %game%.bin > nul
copy /b loader.tap + screen.tap + main.tap %game%.tap > nul

if [%1]==[justcompile] goto :end
if [%1]==[noclean] goto :end

:clean
echo Limpiando
del loader.tap > nul
del screen.tap > nul
del main.tap > nul
del ..\gfx\*.scr > nul

goto :end 

:help
echo "compile.bat help|justcompile|clean|justscripts|justassets|noclean"

:end
echo Hecho!
