.setcpu "65816"
.segment "CODE"
.org $C89E
map_control_0ec89e:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
