.setcpu "65816"
.segment "CODE"
.org $3A0E
map_control_0c3a0e:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
