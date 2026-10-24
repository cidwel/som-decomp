.setcpu "65816"
.segment "CODE"
.org $0E38
map_control_0d0e38:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
