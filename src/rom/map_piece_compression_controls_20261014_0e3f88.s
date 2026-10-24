.setcpu "65816"
.segment "CODE"
.org $3F88
map_control_0e3f88:
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
