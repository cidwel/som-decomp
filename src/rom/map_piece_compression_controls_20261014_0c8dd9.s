.setcpu "65816"
.segment "CODE"
.org $8DD9
map_control_0c8dd9:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
