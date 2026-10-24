.setcpu "65816"
.segment "CODE"
.org $F9A2
map_control_0ef9a2:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
