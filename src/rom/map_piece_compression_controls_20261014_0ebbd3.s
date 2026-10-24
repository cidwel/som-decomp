.setcpu "65816"
.segment "CODE"
.org $BBD3
map_control_0ebbd3:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
