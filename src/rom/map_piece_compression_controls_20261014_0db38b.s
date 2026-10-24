.setcpu "65816"
.segment "CODE"
.org $B38B
map_control_0db38b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
