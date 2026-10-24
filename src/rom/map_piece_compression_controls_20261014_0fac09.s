.setcpu "65816"
.segment "CODE"
.org $AC09
map_control_0fac09:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
