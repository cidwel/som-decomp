.setcpu "65816"
.segment "CODE"
.org $4245
map_control_0e4245:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
