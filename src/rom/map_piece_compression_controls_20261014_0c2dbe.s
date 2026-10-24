.setcpu "65816"
.segment "CODE"
.org $2DBE
map_control_0c2dbe:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
