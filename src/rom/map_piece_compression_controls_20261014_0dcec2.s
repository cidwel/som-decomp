.setcpu "65816"
.segment "CODE"
.org $CEC2
map_control_0dcec2:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
