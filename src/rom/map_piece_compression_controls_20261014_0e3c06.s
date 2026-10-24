.setcpu "65816"
.segment "CODE"
.org $3C06
map_control_0e3c06:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
