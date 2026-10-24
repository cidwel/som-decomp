.setcpu "65816"
.segment "CODE"
.org $54D8
map_control_0e54d8:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
