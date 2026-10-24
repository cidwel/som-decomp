.setcpu "65816"
.segment "CODE"
.org $62F1
map_control_0d62f1:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
