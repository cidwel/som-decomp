.setcpu "65816"
.segment "CODE"
.org $8423
map_control_0e8423:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
