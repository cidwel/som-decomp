.setcpu "65816"
.segment "CODE"
.org $B654
map_control_0eb654:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
