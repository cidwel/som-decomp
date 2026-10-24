.setcpu "65816"
.segment "CODE"
.org $A143
map_control_0da143:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
