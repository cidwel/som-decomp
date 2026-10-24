.setcpu "65816"
.segment "CODE"
.org $DCCD
map_control_0ddccd:
    .byte $CC ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
