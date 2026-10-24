.setcpu "65816"
.segment "CODE"
.org $EF89
map_control_0def89:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
