.setcpu "65816"
.segment "CODE"
.org $D3BD
map_control_0dd3bd:
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
