.setcpu "65816"
.segment "CODE"
.org $2C1A
map_control_0f2c1a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
