.setcpu "65816"
.segment "CODE"
.org $0A10
map_control_0f0a10:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
