.setcpu "65816"
.segment "CODE"
.org $F60F
map_control_0cf60f:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
