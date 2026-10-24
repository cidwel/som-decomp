.setcpu "65816"
.segment "CODE"
.org $F9AB
map_control_0ef9ab:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
