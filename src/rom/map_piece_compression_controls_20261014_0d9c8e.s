.setcpu "65816"
.segment "CODE"
.org $9C8E
map_control_0d9c8e:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
