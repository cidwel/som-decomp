.setcpu "65816"
.segment "CODE"
.org $3130
map_control_0f3130:
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
