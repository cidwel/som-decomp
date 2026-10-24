.setcpu "65816"
.segment "CODE"
.org $FA4D
map_control_0dfa4d:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
