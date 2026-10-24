.setcpu "65816"
.segment "CODE"
.org $052E
map_control_0f052e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
