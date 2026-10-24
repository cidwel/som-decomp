.setcpu "65816"
.segment "CODE"
.org $0ED3
map_control_0d0ed3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
