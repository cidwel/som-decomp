.setcpu "65816"
.segment "CODE"
.org $23CD
map_control_0d23cd:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
