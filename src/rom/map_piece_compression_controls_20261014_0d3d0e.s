.setcpu "65816"
.segment "CODE"
.org $3D0E
map_control_0d3d0e:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
