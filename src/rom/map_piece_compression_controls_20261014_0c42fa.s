.setcpu "65816"
.segment "CODE"
.org $42FA
map_control_0c42fa:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
