.setcpu "65816"
.segment "CODE"
.org $3C34
map_control_0c3c34:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
