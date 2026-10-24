.setcpu "65816"
.segment "CODE"
.org $30B3
map_control_0f30b3:
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count
