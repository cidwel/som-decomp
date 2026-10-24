.setcpu "65816"
.segment "CODE"
.org $BD55
map_control_0ebd55:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
