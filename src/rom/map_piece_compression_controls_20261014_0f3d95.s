.setcpu "65816"
.segment "CODE"
.org $3D95
map_control_0f3d95:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
