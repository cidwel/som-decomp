.setcpu "65816"
.segment "CODE"
.org $4248
map_control_0d4248:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
