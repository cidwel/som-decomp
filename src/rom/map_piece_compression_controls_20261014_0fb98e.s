.setcpu "65816"
.segment "CODE"
.org $B98E
map_control_0fb98e:
    .byte $E8 ; backreference distance high bits
    .byte $5A ; distance low bit/count
