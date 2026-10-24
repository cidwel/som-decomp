.setcpu "65816"
.segment "CODE"
.org $F3BD
map_control_0ff3bd:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
