.setcpu "65816"
.segment "CODE"
.org $7CEA
map_control_0e7cea:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
