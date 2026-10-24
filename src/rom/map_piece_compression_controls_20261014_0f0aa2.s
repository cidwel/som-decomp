.setcpu "65816"
.segment "CODE"
.org $0AA2
map_control_0f0aa2:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
