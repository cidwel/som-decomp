.setcpu "65816"
.segment "CODE"
.org $3D1F
map_control_0d3d1f:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
