.setcpu "65816"
.segment "CODE"
.org $2BCF
map_control_0d2bcf:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
