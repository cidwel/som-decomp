.setcpu "65816"
.segment "CODE"
.org $AAA8
map_control_0faaa8:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
