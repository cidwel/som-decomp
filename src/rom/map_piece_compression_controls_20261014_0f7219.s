.setcpu "65816"
.segment "CODE"
.org $7219
map_control_0f7219:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
