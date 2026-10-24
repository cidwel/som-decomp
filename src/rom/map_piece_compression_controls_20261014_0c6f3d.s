.setcpu "65816"
.segment "CODE"
.org $6F3D
map_control_0c6f3d:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
