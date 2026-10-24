.setcpu "65816"
.segment "CODE"
.org $2477
map_control_0f2477:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
