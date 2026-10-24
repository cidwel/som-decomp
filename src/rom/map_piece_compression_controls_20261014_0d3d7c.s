.setcpu "65816"
.segment "CODE"
.org $3D7C
map_control_0d3d7c:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
