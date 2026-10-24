.setcpu "65816"
.segment "CODE"
.org $42FA
map_control_0d42fa:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
