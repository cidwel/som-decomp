.setcpu "65816"
.segment "CODE"
.org $F90F
map_control_0cf90f:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
