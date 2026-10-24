.setcpu "65816"
.segment "CODE"
.org $7D04
map_control_0d7d04:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $F1 ; progressive-copy count
