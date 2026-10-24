.setcpu "65816"
.segment "CODE"
.org $238D
map_control_0f238d:
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
