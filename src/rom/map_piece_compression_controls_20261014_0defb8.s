.setcpu "65816"
.segment "CODE"
.org $EFB8
map_control_0defb8:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
