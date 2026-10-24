.setcpu "65816"
.segment "CODE"
.org $83E4
map_control_0d83e4:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $E3 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
