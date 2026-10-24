.setcpu "65816"
.segment "CODE"
.org $0748
map_control_0e0748:
    .byte $F4 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
