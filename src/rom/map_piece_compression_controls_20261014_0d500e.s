.setcpu "65816"
.segment "CODE"
.org $500E
map_control_0d500e:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
