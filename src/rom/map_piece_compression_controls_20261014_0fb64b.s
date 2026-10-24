.setcpu "65816"
.segment "CODE"
.org $B64B
map_control_0fb64b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
