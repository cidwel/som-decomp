.setcpu "65816"
.segment "CODE"
.org $5C5D
map_control_0e5c5d:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
