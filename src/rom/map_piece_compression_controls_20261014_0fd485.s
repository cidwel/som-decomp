.setcpu "65816"
.segment "CODE"
.org $D485
map_control_0fd485:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
