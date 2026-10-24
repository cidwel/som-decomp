.setcpu "65816"
.segment "CODE"
.org $DA8E
map_control_0dda8e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
