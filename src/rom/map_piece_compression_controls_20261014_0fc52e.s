.setcpu "65816"
.segment "CODE"
.org $C52E
map_control_0fc52e:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
