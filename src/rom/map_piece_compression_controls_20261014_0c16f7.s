.setcpu "65816"
.segment "CODE"
.org $16F7
map_control_0c16f7:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
