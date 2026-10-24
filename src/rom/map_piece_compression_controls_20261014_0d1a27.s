.setcpu "65816"
.segment "CODE"
.org $1A27
map_control_0d1a27:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
