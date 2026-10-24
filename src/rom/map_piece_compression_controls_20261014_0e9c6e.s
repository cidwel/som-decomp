.setcpu "65816"
.segment "CODE"
.org $9C6E
map_control_0e9c6e:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
