.setcpu "65816"
.segment "CODE"
.org $3774
map_control_0d3774:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
