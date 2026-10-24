.setcpu "65816"
.segment "CODE"
.org $3A4E
map_control_0f3a4e:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
