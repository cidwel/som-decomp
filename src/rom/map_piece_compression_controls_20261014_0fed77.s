.setcpu "65816"
.segment "CODE"
.org $ED77
map_control_0fed77:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
