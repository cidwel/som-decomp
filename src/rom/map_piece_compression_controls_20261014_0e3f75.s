.setcpu "65816"
.segment "CODE"
.org $3F75
map_control_0e3f75:
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
