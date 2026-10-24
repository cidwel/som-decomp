.setcpu "65816"
.segment "CODE"
.org $A90F
map_control_0ea90f:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
