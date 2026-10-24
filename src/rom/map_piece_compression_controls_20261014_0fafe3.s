.setcpu "65816"
.segment "CODE"
.org $AFE3
map_control_0fafe3:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
