.setcpu "65816"
.segment "CODE"
.org $B20E
map_control_0eb20e:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
