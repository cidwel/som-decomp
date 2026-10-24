.setcpu "65816"
.segment "CODE"
.org $B2BB
map_control_0fb2bb:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
