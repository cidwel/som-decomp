.setcpu "65816"
.segment "CODE"
.org $81A2
map_control_0f81a2:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
