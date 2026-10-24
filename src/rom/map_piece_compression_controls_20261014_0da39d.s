.setcpu "65816"
.segment "CODE"
.org $A39D
map_control_0da39d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
