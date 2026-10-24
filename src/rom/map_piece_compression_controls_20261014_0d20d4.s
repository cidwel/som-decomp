.setcpu "65816"
.segment "CODE"
.org $20D4
map_control_0d20d4:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
