.setcpu "65816"
.segment "CODE"
.org $0A4C
map_control_0f0a4c:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
