.setcpu "65816"
.segment "CODE"
.org $3BCD
map_control_0e3bcd:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
