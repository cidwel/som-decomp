.setcpu "65816"
.segment "CODE"
.org $DCB7
map_control_0ddcb7:
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
