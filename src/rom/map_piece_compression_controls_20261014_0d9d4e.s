.setcpu "65816"
.segment "CODE"
.org $9D4E
map_control_0d9d4e:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
