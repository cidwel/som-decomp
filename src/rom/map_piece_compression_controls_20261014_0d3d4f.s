.setcpu "65816"
.segment "CODE"
.org $3D4F
map_control_0d3d4f:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
