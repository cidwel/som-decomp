.setcpu "65816"
.segment "CODE"
.org $2C97
map_control_0f2c97:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
