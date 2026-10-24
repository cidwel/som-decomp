.setcpu "65816"
.segment "CODE"
.org $B6B2
map_control_0fb6b2:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
