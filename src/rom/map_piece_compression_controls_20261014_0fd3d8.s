.setcpu "65816"
.segment "CODE"
.org $D3D8
map_control_0fd3d8:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
