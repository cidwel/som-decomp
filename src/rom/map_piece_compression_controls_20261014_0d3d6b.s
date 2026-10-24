.setcpu "65816"
.segment "CODE"
.org $3D6B
map_control_0d3d6b:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
