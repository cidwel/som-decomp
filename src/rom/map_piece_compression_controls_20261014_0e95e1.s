.setcpu "65816"
.segment "CODE"
.org $95E1
map_control_0e95e1:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
