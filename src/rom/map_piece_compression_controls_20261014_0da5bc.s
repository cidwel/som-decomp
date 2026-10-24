.setcpu "65816"
.segment "CODE"
.org $A5BC
map_control_0da5bc:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
