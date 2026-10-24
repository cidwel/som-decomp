.setcpu "65816"
.segment "CODE"
.org $B03E
map_control_0eb03e:
    .byte $E8 ; backreference distance high bits
    .byte $4F ; distance low bit/count
