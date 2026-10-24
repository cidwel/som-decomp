.setcpu "65816"
.segment "CODE"
.org $B358
map_control_0fb358:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
