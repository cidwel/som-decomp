.setcpu "65816"
.segment "CODE"
.org $76D7
map_control_0e76d7:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
