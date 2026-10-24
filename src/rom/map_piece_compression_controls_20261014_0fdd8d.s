.setcpu "65816"
.segment "CODE"
.org $DD8D
map_control_0fdd8d:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $0F ; distance low bit/count
