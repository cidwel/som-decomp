.setcpu "65816"
.segment "CODE"
.org $1693
map_control_0d1693:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
