.setcpu "65816"
.segment "CODE"
.org $4000
map_control_0e4000:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
