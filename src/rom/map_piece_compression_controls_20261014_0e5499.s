.setcpu "65816"
.segment "CODE"
.org $5499
map_control_0e5499:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
