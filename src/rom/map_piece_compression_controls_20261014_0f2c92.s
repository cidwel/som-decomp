.setcpu "65816"
.segment "CODE"
.org $2C92
map_control_0f2c92:
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
