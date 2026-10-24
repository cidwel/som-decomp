.setcpu "65816"
.segment "CODE"
.org $26B0
map_control_0c26b0:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
