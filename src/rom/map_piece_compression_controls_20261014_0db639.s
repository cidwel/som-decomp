.setcpu "65816"
.segment "CODE"
.org $B639
map_control_0db639:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
