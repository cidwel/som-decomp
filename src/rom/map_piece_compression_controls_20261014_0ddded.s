.setcpu "65816"
.segment "CODE"
.org $DDED
map_control_0ddded:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
