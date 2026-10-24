.setcpu "65816"
.segment "CODE"
.org $90E7
map_control_0f90e7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
