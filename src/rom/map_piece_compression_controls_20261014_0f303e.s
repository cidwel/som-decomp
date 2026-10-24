.setcpu "65816"
.segment "CODE"
.org $303E
map_control_0f303e:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
