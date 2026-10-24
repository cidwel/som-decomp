.setcpu "65816"
.segment "CODE"
.org $3D28
map_control_0e3d28:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
