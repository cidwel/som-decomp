.setcpu "65816"
.segment "CODE"
.org $3D77
map_control_0d3d77:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
