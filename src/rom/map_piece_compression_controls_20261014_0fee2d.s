.setcpu "65816"
.segment "CODE"
.org $EE2D
map_control_0fee2d:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
