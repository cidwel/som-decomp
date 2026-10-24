.setcpu "65816"
.segment "CODE"
.org $962E
map_control_0f962e:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
