.setcpu "65816"
.segment "CODE"
.org $DEA9
map_control_0ddea9:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
