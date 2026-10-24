.setcpu "65816"
.segment "CODE"
.org $54A5
map_control_0c54a5:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
