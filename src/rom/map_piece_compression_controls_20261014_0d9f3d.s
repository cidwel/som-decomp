.setcpu "65816"
.segment "CODE"
.org $9F3D
map_control_0d9f3d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
