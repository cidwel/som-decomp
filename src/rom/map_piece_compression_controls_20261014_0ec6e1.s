.setcpu "65816"
.segment "CODE"
.org $C6E1
map_control_0ec6e1:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
