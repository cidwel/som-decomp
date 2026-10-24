.setcpu "65816"
.segment "CODE"
.org $9DF6
map_control_0d9df6:
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
