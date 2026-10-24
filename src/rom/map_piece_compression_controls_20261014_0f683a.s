.setcpu "65816"
.segment "CODE"
.org $683A
map_control_0f683a:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
