.setcpu "65816"
.segment "CODE"
.org $A8A7
map_control_0fa8a7:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
