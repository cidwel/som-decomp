.setcpu "65816"
.segment "CODE"
.org $0AD3
map_control_0f0ad3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
