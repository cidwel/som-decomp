.setcpu "65816"
.segment "CODE"
.org $3F29
map_control_0c3f29:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
