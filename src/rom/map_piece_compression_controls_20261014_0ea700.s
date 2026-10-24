.setcpu "65816"
.segment "CODE"
.org $A700
map_control_0ea700:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
