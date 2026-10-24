.setcpu "65816"
.segment "CODE"
.org $95B3
map_control_0e95b3:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
