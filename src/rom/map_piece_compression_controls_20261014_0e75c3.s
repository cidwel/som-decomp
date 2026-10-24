.setcpu "65816"
.segment "CODE"
.org $75C3
map_control_0e75c3:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
