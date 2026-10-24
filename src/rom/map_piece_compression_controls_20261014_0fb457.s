.setcpu "65816"
.segment "CODE"
.org $B457
map_control_0fb457:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
