.setcpu "65816"
.segment "CODE"
.org $EFB3
map_control_0defb3:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
