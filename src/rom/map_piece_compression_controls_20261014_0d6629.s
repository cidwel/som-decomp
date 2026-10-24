.setcpu "65816"
.segment "CODE"
.org $6629
map_control_0d6629:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
