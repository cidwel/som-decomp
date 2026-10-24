.setcpu "65816"
.segment "CODE"
.org $8714
map_control_0d8714:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
