.setcpu "65816"
.segment "CODE"
.org $A1E6
map_control_0fa1e6:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
