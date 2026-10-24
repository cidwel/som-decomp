.setcpu "65816"
.segment "CODE"
.org $0AB2
map_control_0f0ab2:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
