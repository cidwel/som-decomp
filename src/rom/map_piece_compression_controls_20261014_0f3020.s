.setcpu "65816"
.segment "CODE"
.org $3020
map_control_0f3020:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
