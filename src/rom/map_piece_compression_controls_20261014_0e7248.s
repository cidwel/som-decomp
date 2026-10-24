.setcpu "65816"
.segment "CODE"
.org $7248
map_control_0e7248:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
