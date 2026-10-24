.setcpu "65816"
.segment "CODE"
.org $50E9
map_control_0d50e9:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
