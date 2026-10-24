.setcpu "65816"
.segment "CODE"
.org $B3D7
map_control_0eb3d7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
