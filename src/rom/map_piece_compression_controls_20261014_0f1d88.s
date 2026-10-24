.setcpu "65816"
.segment "CODE"
.org $1D88
map_control_0f1d88:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
