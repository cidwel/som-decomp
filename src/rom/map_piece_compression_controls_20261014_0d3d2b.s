.setcpu "65816"
.segment "CODE"
.org $3D2B
map_control_0d3d2b:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
