.setcpu "65816"
.segment "CODE"
.org $79AA
map_control_0d79aa:
    .byte $D9 ; same-value copy count/distance
    .byte $D7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
