.setcpu "65816"
.segment "CODE"
.org $18E7
map_control_0d18e7:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
