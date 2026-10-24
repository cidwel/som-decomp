.setcpu "65816"
.segment "CODE"
.org $DCAC
map_control_0ddcac:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
