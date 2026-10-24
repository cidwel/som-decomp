.setcpu "65816"
.segment "CODE"
.org $1A19
map_control_0d1a19:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
