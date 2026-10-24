.setcpu "65816"
.segment "CODE"
.org $A1AC
map_control_0fa1ac:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
