.setcpu "65816"
.segment "CODE"
.org $3EEE
map_control_0d3eee:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
