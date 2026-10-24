.setcpu "65816"
.segment "CODE"
.org $D2C2
map_control_0dd2c2:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
