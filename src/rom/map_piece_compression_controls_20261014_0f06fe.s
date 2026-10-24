.setcpu "65816"
.segment "CODE"
.org $06FE
map_control_0f06fe:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
