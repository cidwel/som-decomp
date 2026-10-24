.setcpu "65816"
.segment "CODE"
.org $3D30
map_control_0d3d30:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
