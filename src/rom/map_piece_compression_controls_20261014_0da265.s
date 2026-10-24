.setcpu "65816"
.segment "CODE"
.org $A265
map_control_0da265:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
