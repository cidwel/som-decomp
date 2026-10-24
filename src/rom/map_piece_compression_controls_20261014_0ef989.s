.setcpu "65816"
.segment "CODE"
.org $F989
map_control_0ef989:
    .byte $C3 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
