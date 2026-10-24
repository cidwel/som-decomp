.setcpu "65816"
.segment "CODE"
.org $3106
map_control_0e3106:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
