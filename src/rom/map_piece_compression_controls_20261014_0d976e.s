.setcpu "65816"
.segment "CODE"
.org $976E
map_control_0d976e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
