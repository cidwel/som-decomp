.setcpu "65816"
.segment "CODE"
.org $B776
map_control_0fb776:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
