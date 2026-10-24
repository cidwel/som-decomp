.setcpu "65816"
.segment "CODE"
.org $2D3D
map_control_0f2d3d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
