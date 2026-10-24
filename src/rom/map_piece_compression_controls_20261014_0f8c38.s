.setcpu "65816"
.segment "CODE"
.org $8C38
map_control_0f8c38:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
