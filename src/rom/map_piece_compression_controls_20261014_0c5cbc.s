.setcpu "65816"
.segment "CODE"
.org $5CBC
map_control_0c5cbc:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
