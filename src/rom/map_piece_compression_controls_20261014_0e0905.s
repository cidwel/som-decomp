.setcpu "65816"
.segment "CODE"
.org $0905
map_control_0e0905:
    .byte $F4 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
