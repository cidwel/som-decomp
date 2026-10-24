.setcpu "65816"
.segment "CODE"
.org $6B19
map_control_0f6b19:
    .byte $EC ; backreference distance high bits
    .byte $0B ; distance low bit/count
