.setcpu "65816"
.segment "CODE"
.org $3D3E
map_control_0d3d3e:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
