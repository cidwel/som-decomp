.setcpu "65816"
.segment "CODE"
.org $0615
map_control_0f0615:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
