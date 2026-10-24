.setcpu "65816"
.segment "CODE"
.org $EC68
map_control_0fec68:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
