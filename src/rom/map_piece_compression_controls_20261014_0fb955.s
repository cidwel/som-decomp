.setcpu "65816"
.segment "CODE"
.org $B955
map_control_0fb955:
    .byte $C7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
