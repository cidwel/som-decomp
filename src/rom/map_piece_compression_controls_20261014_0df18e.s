.setcpu "65816"
.segment "CODE"
.org $F18E
map_control_0df18e:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
