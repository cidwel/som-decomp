.setcpu "65816"
.segment "CODE"
.org $50E5
map_control_0d50e5:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
