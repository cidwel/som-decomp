.setcpu "65816"
.segment "CODE"
.org $292F
map_control_0e292f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
