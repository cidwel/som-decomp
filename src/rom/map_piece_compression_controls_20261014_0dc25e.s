.setcpu "65816"
.segment "CODE"
.org $C25E
map_control_0dc25e:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
