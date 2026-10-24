.setcpu "65816"
.segment "CODE"
.org $0A0C
map_control_0f0a0c:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
