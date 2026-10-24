.setcpu "65816"
.segment "CODE"
.org $E955
map_control_0de955:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
