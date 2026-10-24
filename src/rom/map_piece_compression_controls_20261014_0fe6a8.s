.setcpu "65816"
.segment "CODE"
.org $E6A8
map_control_0fe6a8:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
