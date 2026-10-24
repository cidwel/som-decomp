.setcpu "65816"
.segment "CODE"
.org $73E6
map_control_0e73e6:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
