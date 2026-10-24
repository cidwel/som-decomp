.setcpu "65816"
.segment "CODE"
.org $B30B
map_control_0eb30b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
