.setcpu "65816"
.segment "CODE"
.org $3626
map_control_0d3626:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
