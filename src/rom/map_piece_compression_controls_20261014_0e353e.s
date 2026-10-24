.setcpu "65816"
.segment "CODE"
.org $353E
map_control_0e353e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
