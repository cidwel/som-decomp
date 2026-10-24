.setcpu "65816"
.segment "CODE"
.org $0AE9
map_control_0f0ae9:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
