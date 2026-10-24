.setcpu "65816"
.segment "CODE"
.org $B65E
map_control_0fb65e:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
