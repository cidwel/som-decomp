.setcpu "65816"
.segment "CODE"
.org $109D
map_control_0d109d:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
