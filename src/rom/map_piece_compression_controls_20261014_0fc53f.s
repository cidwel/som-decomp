.setcpu "65816"
.segment "CODE"
.org $C53F
map_control_0fc53f:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
