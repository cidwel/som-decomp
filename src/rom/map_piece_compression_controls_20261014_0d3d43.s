.setcpu "65816"
.segment "CODE"
.org $3D43
map_control_0d3d43:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
