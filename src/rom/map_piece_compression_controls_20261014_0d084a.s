.setcpu "65816"
.segment "CODE"
.org $084A
map_control_0d084a:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
