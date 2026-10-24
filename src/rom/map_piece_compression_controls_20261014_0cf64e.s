.setcpu "65816"
.segment "CODE"
.org $F64E
map_control_0cf64e:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
