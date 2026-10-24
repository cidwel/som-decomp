.setcpu "65816"
.segment "CODE"
.org $7500
map_control_0e7500:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
