.setcpu "65816"
.segment "CODE"
.org $FA3A
map_control_0dfa3a:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
