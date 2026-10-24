.setcpu "65816"
.segment "CODE"
.org $C90D
map_control_0dc90d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
