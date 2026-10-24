.setcpu "65816"
.segment "CODE"
.org $A576
map_control_0da576:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
