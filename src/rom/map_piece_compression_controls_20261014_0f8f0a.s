.setcpu "65816"
.segment "CODE"
.org $8F0A
map_control_0f8f0a:
    .byte $E9 ; backreference distance high bits
    .byte $1F ; distance low bit/count
