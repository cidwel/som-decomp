.setcpu "65816"
.segment "CODE"
.org $F347
map_control_0ef347:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
