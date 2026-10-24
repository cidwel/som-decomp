.setcpu "65816"
.segment "CODE"
.org $3D39
map_control_0e3d39:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
