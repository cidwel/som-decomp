.setcpu "65816"
.segment "CODE"
.org $4F78
map_control_0e4f78:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $F1 ; progressive-copy count
