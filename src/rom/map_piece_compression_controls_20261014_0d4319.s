.setcpu "65816"
.segment "CODE"
.org $4319
map_control_0d4319:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
