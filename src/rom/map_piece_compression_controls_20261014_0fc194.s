.setcpu "65816"
.segment "CODE"
.org $C194
map_control_0fc194:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
