.setcpu "65816"
.segment "CODE"
.org $FA61
map_control_0cfa61:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
