.setcpu "65816"
.segment "CODE"
.org $4F29
map_control_0d4f29:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
