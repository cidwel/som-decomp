.setcpu "65816"
.segment "CODE"
.org $3903
map_control_0c3903:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
