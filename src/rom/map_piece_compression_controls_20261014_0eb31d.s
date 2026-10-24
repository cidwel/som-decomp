.setcpu "65816"
.segment "CODE"
.org $B31D
map_control_0eb31d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
