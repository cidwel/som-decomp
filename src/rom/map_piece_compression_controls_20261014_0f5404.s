.setcpu "65816"
.segment "CODE"
.org $5404
map_control_0f5404:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
