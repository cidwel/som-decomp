.setcpu "65816"
.segment "CODE"
.org $88DC
map_control_0e88dc:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
