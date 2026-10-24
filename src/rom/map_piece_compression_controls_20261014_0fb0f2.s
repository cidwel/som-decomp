.setcpu "65816"
.segment "CODE"
.org $B0F2
map_control_0fb0f2:
    .byte $D2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
