.setcpu "65816"
.segment "CODE"
.org $ED19
map_control_0fed19:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
