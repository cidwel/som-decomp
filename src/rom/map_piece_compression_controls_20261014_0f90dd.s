.setcpu "65816"
.segment "CODE"
.org $90DD
map_control_0f90dd:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
