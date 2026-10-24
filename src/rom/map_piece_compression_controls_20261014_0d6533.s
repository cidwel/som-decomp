.setcpu "65816"
.segment "CODE"
.org $6533
map_control_0d6533:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
