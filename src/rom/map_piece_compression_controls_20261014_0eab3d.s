.setcpu "65816"
.segment "CODE"
.org $AB3D
map_control_0eab3d:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
