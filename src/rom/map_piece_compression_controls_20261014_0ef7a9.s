.setcpu "65816"
.segment "CODE"
.org $F7A9
map_control_0ef7a9:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
