.setcpu "65816"
.segment "CODE"
.org $166F
map_control_0d166f:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
