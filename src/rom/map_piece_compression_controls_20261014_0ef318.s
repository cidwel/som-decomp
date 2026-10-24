.setcpu "65816"
.segment "CODE"
.org $F318
map_control_0ef318:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
