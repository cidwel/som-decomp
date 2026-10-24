.setcpu "65816"
.segment "CODE"
.org $5334
map_control_0c5334:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
