.setcpu "65816"
.segment "CODE"
.org $3D54
map_control_0d3d54:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
