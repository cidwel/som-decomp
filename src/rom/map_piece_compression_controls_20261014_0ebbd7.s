.setcpu "65816"
.segment "CODE"
.org $BBD7
map_control_0ebbd7:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
