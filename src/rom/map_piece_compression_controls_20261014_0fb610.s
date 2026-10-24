.setcpu "65816"
.segment "CODE"
.org $B610
map_control_0fb610:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
