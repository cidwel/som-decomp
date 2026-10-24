.setcpu "65816"
.segment "CODE"
.org $EA9B
map_control_0fea9b:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
