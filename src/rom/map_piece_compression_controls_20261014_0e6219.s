.setcpu "65816"
.segment "CODE"
.org $6219
map_control_0e6219:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
