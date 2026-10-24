.setcpu "65816"
.segment "CODE"
.org $C13D
map_control_0ec13d:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
