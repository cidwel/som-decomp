.setcpu "65816"
.segment "CODE"
.org $0D2D
map_control_0c0d2d:
    .byte $D4 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $D5 ; same-value copy count/distance
