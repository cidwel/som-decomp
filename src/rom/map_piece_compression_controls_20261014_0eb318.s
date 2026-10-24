.setcpu "65816"
.segment "CODE"
.org $B318
map_control_0eb318:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
