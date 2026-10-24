.setcpu "65816"
.segment "CODE"
.org $A1B5
map_control_0fa1b5:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
