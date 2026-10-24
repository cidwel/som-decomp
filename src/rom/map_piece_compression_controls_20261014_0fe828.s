.setcpu "65816"
.segment "CODE"
.org $E828
map_control_0fe828:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
