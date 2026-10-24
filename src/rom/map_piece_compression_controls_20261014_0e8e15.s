.setcpu "65816"
.segment "CODE"
.org $8E15
map_control_0e8e15:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
