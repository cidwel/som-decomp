.setcpu "65816"
.segment "CODE"
.org $507A
map_control_0d507a:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
