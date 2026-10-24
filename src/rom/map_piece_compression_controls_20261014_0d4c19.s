.setcpu "65816"
.segment "CODE"
.org $4C19
map_control_0d4c19:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
