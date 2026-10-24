.setcpu "65816"
.segment "CODE"
.org $70ED
map_control_0f70ed:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
