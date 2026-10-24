.setcpu "65816"
.segment "CODE"
.org $1826
map_control_0d1826:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
