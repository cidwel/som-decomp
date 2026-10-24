.setcpu "65816"
.segment "CODE"
.org $3AD3
map_control_0d3ad3:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
