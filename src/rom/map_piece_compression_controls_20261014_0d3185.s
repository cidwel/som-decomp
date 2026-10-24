.setcpu "65816"
.segment "CODE"
.org $3185
map_control_0d3185:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
