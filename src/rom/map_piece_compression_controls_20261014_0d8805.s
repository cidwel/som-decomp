.setcpu "65816"
.segment "CODE"
.org $8805
map_control_0d8805:
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
