.setcpu "65816"
.segment "CODE"
.org $3C1F
map_control_0c3c1f:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
