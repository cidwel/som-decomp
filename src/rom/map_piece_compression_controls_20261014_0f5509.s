.setcpu "65816"
.segment "CODE"
.org $5509
map_control_0f5509:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
