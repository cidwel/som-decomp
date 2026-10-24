.setcpu "65816"
.segment "CODE"
.org $0DD3
map_control_0f0dd3:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
