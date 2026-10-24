.setcpu "65816"
.segment "CODE"
.org $4BC6
map_control_0d4bc6:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
