.setcpu "65816"
.segment "CODE"
.org $3D8F
map_control_0d3d8f:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
