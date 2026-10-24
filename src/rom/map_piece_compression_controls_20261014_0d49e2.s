.setcpu "65816"
.segment "CODE"
.org $49E2
map_control_0d49e2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
