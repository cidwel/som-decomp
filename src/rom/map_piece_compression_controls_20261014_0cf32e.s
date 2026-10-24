.setcpu "65816"
.segment "CODE"
.org $F32E
map_control_0cf32e:
    .byte $E8 ; backreference distance high bits
    .byte $42 ; distance low bit/count
