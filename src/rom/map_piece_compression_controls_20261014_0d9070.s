.setcpu "65816"
.segment "CODE"
.org $9070
map_control_0d9070:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
