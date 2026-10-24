.setcpu "65816"
.segment "CODE"
.org $DEF3
map_control_0edef3:
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
