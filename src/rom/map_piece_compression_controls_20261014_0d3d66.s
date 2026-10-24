.setcpu "65816"
.segment "CODE"
.org $3D66
map_control_0d3d66:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
