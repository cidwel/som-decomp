.setcpu "65816"
.segment "CODE"
.org $4D3D
map_control_0e4d3d:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
