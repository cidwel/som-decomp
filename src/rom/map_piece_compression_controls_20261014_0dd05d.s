.setcpu "65816"
.segment "CODE"
.org $D05D
map_control_0dd05d:
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
