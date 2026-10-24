.setcpu "65816"
.segment "CODE"
.org $F6AB
map_control_0cf6ab:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
