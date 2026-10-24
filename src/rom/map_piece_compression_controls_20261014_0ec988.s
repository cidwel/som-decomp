.setcpu "65816"
.segment "CODE"
.org $C988
map_control_0ec988:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
