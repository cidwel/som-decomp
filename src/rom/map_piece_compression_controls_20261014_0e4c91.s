.setcpu "65816"
.segment "CODE"
.org $4C91
map_control_0e4c91:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
