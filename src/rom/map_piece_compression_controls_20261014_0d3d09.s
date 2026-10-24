.setcpu "65816"
.segment "CODE"
.org $3D09
map_control_0d3d09:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
