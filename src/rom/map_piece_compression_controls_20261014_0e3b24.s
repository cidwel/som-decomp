.setcpu "65816"
.segment "CODE"
.org $3B24
map_control_0e3b24:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
