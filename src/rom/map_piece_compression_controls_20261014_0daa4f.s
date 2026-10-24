.setcpu "65816"
.segment "CODE"
.org $AA4F
map_control_0daa4f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
