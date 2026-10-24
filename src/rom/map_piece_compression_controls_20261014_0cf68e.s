.setcpu "65816"
.segment "CODE"
.org $F68E
map_control_0cf68e:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
