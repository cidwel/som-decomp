.setcpu "65816"
.segment "CODE"
.org $3FE0
map_control_0e3fe0:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
