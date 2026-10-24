.setcpu "65816"
.segment "CODE"
.org $A6E9
map_control_0da6e9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
