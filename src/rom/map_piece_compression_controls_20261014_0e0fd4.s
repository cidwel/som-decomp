.setcpu "65816"
.segment "CODE"
.org $0FD4
map_control_0e0fd4:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
