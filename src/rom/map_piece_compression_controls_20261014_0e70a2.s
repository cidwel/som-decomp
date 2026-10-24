.setcpu "65816"
.segment "CODE"
.org $70A2
map_control_0e70a2:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
