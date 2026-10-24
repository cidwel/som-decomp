.setcpu "65816"
.segment "CODE"
.org $1F2E
map_control_0e1f2e:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
