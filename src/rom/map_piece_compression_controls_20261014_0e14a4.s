.setcpu "65816"
.segment "CODE"
.org $14A4
map_control_0e14a4:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
