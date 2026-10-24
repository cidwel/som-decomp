.setcpu "65816"
.segment "CODE"
.org $3D01
map_control_0e3d01:
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
