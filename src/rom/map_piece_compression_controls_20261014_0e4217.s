.setcpu "65816"
.segment "CODE"
.org $4217
map_control_0e4217:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
