.setcpu "65816"
.segment "CODE"
.org $2A5D
map_control_0d2a5d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
