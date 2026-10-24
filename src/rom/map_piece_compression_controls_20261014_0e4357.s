.setcpu "65816"
.segment "CODE"
.org $4357
map_control_0e4357:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
