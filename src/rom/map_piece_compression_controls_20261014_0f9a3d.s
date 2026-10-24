.setcpu "65816"
.segment "CODE"
.org $9A3D
map_control_0f9a3d:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
