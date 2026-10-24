.setcpu "65816"
.segment "CODE"
.org $53FB
map_control_0e53fb:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
