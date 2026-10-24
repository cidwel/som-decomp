.setcpu "65816"
.segment "CODE"
.org $B140
map_control_0eb140:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
