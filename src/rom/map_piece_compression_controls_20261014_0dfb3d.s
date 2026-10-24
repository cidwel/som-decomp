.setcpu "65816"
.segment "CODE"
.org $FB3D
map_control_0dfb3d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
