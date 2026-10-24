.setcpu "65816"
.segment "CODE"
.org $EF73
map_control_0def73:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
