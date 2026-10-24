.setcpu "65816"
.segment "CODE"
.org $C472
map_control_0ec472:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
