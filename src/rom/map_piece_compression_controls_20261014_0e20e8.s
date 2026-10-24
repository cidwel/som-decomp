.setcpu "65816"
.segment "CODE"
.org $20E8
map_control_0e20e8:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
