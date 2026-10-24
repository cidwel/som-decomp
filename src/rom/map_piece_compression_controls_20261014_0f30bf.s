.setcpu "65816"
.segment "CODE"
.org $30BF
map_control_0f30bf:
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count
