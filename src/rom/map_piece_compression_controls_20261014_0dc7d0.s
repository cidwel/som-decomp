.setcpu "65816"
.segment "CODE"
.org $C7D0
map_control_0dc7d0:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
