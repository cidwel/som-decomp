.setcpu "65816"
.segment "CODE"
.org $6447
map_control_0d6447:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
