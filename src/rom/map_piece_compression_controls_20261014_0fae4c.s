.setcpu "65816"
.segment "CODE"
.org $AE4C
map_control_0fae4c:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
