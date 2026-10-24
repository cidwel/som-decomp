.setcpu "65816"
.segment "CODE"
.org $3D8A
map_control_0d3d8a:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
