.setcpu "65816"
.segment "CODE"
.org $F9F1
map_control_0ef9f1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
