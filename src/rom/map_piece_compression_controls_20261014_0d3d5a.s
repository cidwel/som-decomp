.setcpu "65816"
.segment "CODE"
.org $3D5A
map_control_0d3d5a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
