.setcpu "65816"
.segment "CODE"
.org $D65C
map_control_0dd65c:
    .byte $D1 ; same-value copy count/distance
    .byte $D1 ; same-value copy count/distance
    .byte $D4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
