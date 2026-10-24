.setcpu "65816"
.segment "CODE"
.org $7C68
map_control_0e7c68:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
