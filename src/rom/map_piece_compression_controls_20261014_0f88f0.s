.setcpu "65816"
.segment "CODE"
.org $88F0
map_control_0f88f0:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
