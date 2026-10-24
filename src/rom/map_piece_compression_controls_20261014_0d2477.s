.setcpu "65816"
.segment "CODE"
.org $2477
map_control_0d2477:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
