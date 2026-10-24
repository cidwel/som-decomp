.setcpu "65816"
.segment "CODE"
.org $E858
map_control_0fe858:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
