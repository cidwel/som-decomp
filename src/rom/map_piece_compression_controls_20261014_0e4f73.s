.setcpu "65816"
.segment "CODE"
.org $4F73
map_control_0e4f73:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
