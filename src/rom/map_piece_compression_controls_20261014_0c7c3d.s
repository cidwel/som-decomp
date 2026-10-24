.setcpu "65816"
.segment "CODE"
.org $7C3D
map_control_0c7c3d:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
