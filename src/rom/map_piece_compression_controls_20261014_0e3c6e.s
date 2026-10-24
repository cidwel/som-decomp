.setcpu "65816"
.segment "CODE"
.org $3C6E
map_control_0e3c6e:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
