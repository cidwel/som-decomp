.setcpu "65816"
.segment "CODE"
.org $2006
map_control_0c2006:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
