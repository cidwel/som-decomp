.setcpu "65816"
.segment "CODE"
.org $20BD
map_control_0e20bd:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
