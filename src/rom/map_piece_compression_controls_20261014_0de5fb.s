.setcpu "65816"
.segment "CODE"
.org $E5FB
map_control_0de5fb:
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
