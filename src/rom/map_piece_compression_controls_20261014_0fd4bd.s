.setcpu "65816"
.segment "CODE"
.org $D4BD
map_control_0fd4bd:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
