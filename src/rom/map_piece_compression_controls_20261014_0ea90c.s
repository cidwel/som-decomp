.setcpu "65816"
.segment "CODE"
.org $A90C
map_control_0ea90c:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
