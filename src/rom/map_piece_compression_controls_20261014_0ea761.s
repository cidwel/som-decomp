.setcpu "65816"
.segment "CODE"
.org $A761
map_control_0ea761:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
