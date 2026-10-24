.setcpu "65816"
.segment "CODE"
.org $3D9A
map_control_0f3d9a:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
