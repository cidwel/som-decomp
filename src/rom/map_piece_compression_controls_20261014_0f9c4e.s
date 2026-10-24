.setcpu "65816"
.segment "CODE"
.org $9C4E
map_control_0f9c4e:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
