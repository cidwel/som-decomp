.setcpu "65816"
.segment "CODE"
.org $F187
map_control_0ef187:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
