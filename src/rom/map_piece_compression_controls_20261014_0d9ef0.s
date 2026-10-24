.setcpu "65816"
.segment "CODE"
.org $9EF0
map_control_0d9ef0:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
