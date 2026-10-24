.setcpu "65816"
.segment "CODE"
.org $CC78
map_control_0dcc78:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
