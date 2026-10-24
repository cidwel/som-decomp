.setcpu "65816"
.segment "CODE"
.org $C1CF
map_control_0ec1cf:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
