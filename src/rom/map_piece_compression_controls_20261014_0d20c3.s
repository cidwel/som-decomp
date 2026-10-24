.setcpu "65816"
.segment "CODE"
.org $20C3
map_control_0d20c3:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
