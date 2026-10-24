.setcpu "65816"
.segment "CODE"
.org $F657
map_control_0cf657:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
