// MTE MK1 (la Churrera) v5.0
// Copyleft 2010-2014, 2020 by the Mojon Twins

// Generated from instrumentos.asm
// Generated by wyztrackerparser v0.1 20200515

#asm
     
    ; Tabla de instrumentos 
    .TABLA_PAUTAS
        defw PAUTA_0,PAUTA_1,PAUTA_2,PAUTA_3,PAUTA_4,PAUTA_5,0,PAUTA_7,PAUTA_8,PAUTA_9,PAUTA_10,PAUTA_11,PAUTA_12,PAUTA_13,PAUTA_14,PAUTA_15,PAUTA_16 
     
    ; Tabla de efectos 
    .TABLA_SONIDOS
        defw SONIDO0,SONIDO1,SONIDO2,SONIDO3,SONIDO4,SONIDO5,SONIDO6,SONIDO7,SONIDO8,SONIDO9 
     
    ;Pautas (instrumentos) 
    ;Instrumento 'Piano' 
    .PAUTA_0
        defb 8,0,7,0,6,0,5,0,129 
    ;Instrumento 'Piano Reverb' 
    .PAUTA_1
        defb 11,0,12,0,11,0,10,0,9,0,9,0,9,0,9,0,9,0,9,0,8,0,8,0,8,0,8,0,136 
    ;Instrumento 'Fade In FX' 
    .PAUTA_2
        defb 2,0,3,0,4,8,4,-1,5,-4,5,20,5,-24,4,4,132 
    ;Instrumento 'Guitar 1' 
    .PAUTA_3
        defb 14,0,14,0,12,0,12,0,10,0,9,1,9,1,9,-1,8,-1,8,0,8,0,134 
    ;Instrumento 'Guitar 2' 
    .PAUTA_4
        defb 13,0,13,0,12,0,11,0,9,0,8,1,8,0,8,0,8,-1,8,0,8,0,134 
    ;Instrumento 'Eco guitar' 
    .PAUTA_5
        defb 7,0,7,0,7,0,6,0,6,0,6,0,6,0,6,0,5,0,5,0,5,0,5,0,5,0,4,0,4,0,4,0,4,0,3,0,0,0,129 
    ;Instrumento 'Solo Guitar' 
    .PAUTA_7
        defb 76,0,11,0,11,0,11,0,10,0,9,1,9,0,9,-1,9,0,9,0,9,-1,9,0,9,1,9,0,9,0,138 
    ;Instrumento 'Eco Solo Guitar' 
    .PAUTA_8
        defb 70,0,6,0,6,0,5,0,5,0,5,0,5,0,5,0,4,0,4,0,4,0,4,0,4,0,4,0,3,0,3,0,3,0,3,0,3,0,3,0,2,0,2,0,2,0,1,0,129 
    ;Instrumento 'Slap Bass' 
    .PAUTA_9
        defb 45,0,12,4,11,-4,10,3,9,-5,8,0,129 
    ;Instrumento 'Robo' 
    .PAUTA_10
        defb 7,-1,23,5,23,9,6,0,22,5,22,9,5,0,21,5,21,9,4,0,20,5,20,9,3,0,19,5,19,9,131 
    ;Instrumento 'Chip' 
    .PAUTA_11
        defb 70,0,7,0,40,0,7,0,6,0,5,0,129 
    ;Instrumento 'Clipclop' 
    .PAUTA_12
        defb 12,0,11,0,10,0,9,0,9,0,9,0,9,0,9,0,8,0,8,0,8,0,8,0,8,0,138 
    ;Instrumento 'Eco' 
    .PAUTA_13
        defb 9,0,8,0,7,0,6,0,129 
    ;Instrumento 'Harmonica' 
    .PAUTA_14
        defb 42,0,11,0,12,0,11,0,10,0,9,0,129 
    ;Instrumento 'Onda' 
    .PAUTA_15
        defb 73,0,10,0,11,0,12,0,11,0,10,0,9,0,6,0,129 
    ;Instrumento 'Teeth' 
    .PAUTA_16
        defb 73,0,10,0,42,0,9,0,8,0,7,0,7,0,7,0,7,0,6,0,6,0,6,0,6,0,136 
     
    ;Efectos 
    ;Efecto 'Bass Drum' 
    .SONIDO0
        defb 209,60,0,15,124,0,255 
    ;Efecto 'Bass Drum Vol 2' 
    .SONIDO1
        defb 186,58,0,0,102,0,162,131,0,255 
    ;Efecto 'Drum' 
    .SONIDO2
        defb 231,46,0,115,43,1,100,42,2,255 
    ;Efecto 'Drum 2' 
    .SONIDO3
        defb 19,63,0,0,13,1,0,10,1,0,8,1,255 
    ;Efecto 'Hit hat' 
    .SONIDO4
        defb 0,12,1,0,6,1,255 
    ;Efecto 'Hit Hat 2' 
    .SONIDO5
        defb 0,12,1,255 
    ;Efecto 'Bongo 1' 
    .SONIDO6
        defb 186,30,0,232,25,0,0,40,0,69,38,0,255 
    ;Efecto 'Bongo 2' 
    .SONIDO7
        defb 69,46,0,186,41,0,46,56,0,232,54,0,255 
    ;Efecto 'Drum 3' 
    .SONIDO8
        defb 232,44,0,0,92,5,23,108,5,232,124,5,255 
    ;Efecto 'Mute' 
    .SONIDO9
        defb 0,0,0,255 
     
    ;Frecuencias para las notas 
#endasm
