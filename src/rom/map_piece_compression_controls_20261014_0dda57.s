.setcpu "65816"
.segment "CODE"
.org $DA57
map_control_0dda57:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
