.setcpu "65816"
.segment "CODE"
.org $2C1F
map_control_0d2c1f:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
