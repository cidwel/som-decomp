.setcpu "65816"
.segment "CODE"
.org $19A8
map_control_0d19a8:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
