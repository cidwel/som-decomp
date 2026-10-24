.setcpu "65816"
.segment "CODE"
.org $90F5
map_control_0f90f5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
