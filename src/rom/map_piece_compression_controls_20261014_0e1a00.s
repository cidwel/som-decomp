.setcpu "65816"
.segment "CODE"
.org $1A00
map_control_0e1a00:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
