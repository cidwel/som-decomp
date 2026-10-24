.setcpu "65816"
.segment "CODE"
.org $88D0
map_control_0c88d0:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
