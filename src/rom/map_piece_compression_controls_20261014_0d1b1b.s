.setcpu "65816"
.segment "CODE"
.org $1B1B
map_control_0d1b1b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
