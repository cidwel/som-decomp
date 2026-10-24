.setcpu "65816"
.segment "CODE"
.org $BF2C
map_control_0fbf2c:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
