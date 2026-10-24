.setcpu "65816"
.segment "CODE"
.org $B56D
map_control_0db56d:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
