.setcpu "65816"
.segment "CODE"
.org $0A69
map_control_0d0a69:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
