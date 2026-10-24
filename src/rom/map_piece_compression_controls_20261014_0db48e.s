.setcpu "65816"
.segment "CODE"
.org $B48E
map_control_0db48e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
