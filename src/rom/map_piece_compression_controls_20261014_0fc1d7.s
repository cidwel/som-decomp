.setcpu "65816"
.segment "CODE"
.org $C1D7
map_control_0fc1d7:
    .byte $F3 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
