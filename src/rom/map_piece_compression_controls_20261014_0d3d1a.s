.setcpu "65816"
.segment "CODE"
.org $3D1A
map_control_0d3d1a:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
