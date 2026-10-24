.setcpu "65816"
.segment "CODE"
.org $3D9C
map_control_0d3d9c:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
