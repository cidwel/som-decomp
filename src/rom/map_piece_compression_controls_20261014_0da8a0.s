.setcpu "65816"
.segment "CODE"
.org $A8A0
map_control_0da8a0:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
