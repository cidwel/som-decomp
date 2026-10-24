.setcpu "65816"
.segment "CODE"
.org $C1CC
map_control_0fc1cc:
    .byte $F3 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
