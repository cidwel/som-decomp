.setcpu "65816"
.segment "CODE"
.org $5DF7
map_control_0e5df7:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
