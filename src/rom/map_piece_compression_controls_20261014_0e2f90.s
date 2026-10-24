.setcpu "65816"
.segment "CODE"
.org $2F90
map_control_0e2f90:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
