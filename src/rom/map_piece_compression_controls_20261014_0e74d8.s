.setcpu "65816"
.segment "CODE"
.org $74D8
map_control_0e74d8:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
