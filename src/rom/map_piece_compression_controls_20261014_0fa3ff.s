.setcpu "65816"
.segment "CODE"
.org $A3FF
map_control_0fa3ff:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
