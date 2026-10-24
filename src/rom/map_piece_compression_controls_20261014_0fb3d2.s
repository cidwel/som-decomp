.setcpu "65816"
.segment "CODE"
.org $B3D2
map_control_0fb3d2:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
