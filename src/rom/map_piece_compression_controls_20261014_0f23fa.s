.setcpu "65816"
.segment "CODE"
.org $23FA
map_control_0f23fa:
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
