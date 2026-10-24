.setcpu "65816"
.segment "CODE"
.org $BF2C
map_control_0ebf2c:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
