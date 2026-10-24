.setcpu "65816"
.segment "CODE"
.org $0A8C
map_control_0f0a8c:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
