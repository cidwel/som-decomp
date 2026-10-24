.setcpu "65816"
.segment "CODE"
.org $6473
map_control_0c6473:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
