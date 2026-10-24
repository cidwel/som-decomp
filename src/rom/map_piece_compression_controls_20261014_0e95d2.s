.setcpu "65816"
.segment "CODE"
.org $95D2
map_control_0e95d2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
