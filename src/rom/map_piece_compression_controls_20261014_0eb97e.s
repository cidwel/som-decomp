.setcpu "65816"
.segment "CODE"
.org $B97E
map_control_0eb97e:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
