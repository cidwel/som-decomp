.setcpu "65816"
.segment "CODE"
.org $023F
map_control_0e023f:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
