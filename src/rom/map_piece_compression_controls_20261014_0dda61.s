.setcpu "65816"
.segment "CODE"
.org $DA61
map_control_0dda61:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
