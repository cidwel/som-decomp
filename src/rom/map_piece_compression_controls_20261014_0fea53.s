.setcpu "65816"
.segment "CODE"
.org $EA53
map_control_0fea53:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
