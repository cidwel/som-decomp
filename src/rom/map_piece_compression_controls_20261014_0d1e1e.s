.setcpu "65816"
.segment "CODE"
.org $1E1E
map_control_0d1e1e:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
