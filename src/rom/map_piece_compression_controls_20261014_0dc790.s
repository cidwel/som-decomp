.setcpu "65816"
.segment "CODE"
.org $C790
map_control_0dc790:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
