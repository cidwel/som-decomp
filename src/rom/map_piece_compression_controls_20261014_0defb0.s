.setcpu "65816"
.segment "CODE"
.org $EFB0
map_control_0defb0:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
