.setcpu "65816"
.segment "CODE"
.org $7C5E
map_control_0f7c5e:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
