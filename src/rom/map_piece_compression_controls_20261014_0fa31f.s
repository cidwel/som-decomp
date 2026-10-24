.setcpu "65816"
.segment "CODE"
.org $A31F
map_control_0fa31f:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
