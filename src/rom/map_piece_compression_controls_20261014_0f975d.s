.setcpu "65816"
.segment "CODE"
.org $975D
map_control_0f975d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
