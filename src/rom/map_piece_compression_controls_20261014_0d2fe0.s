.setcpu "65816"
.segment "CODE"
.org $2FE0
map_control_0d2fe0:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
