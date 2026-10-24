.setcpu "65816"
.segment "CODE"
.org $FF2D
map_control_0eff2d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
