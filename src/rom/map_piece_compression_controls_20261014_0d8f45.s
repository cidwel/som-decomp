.setcpu "65816"
.segment "CODE"
.org $8F45
map_control_0d8f45:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
