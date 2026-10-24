.setcpu "65816"
.segment "CODE"
.org $AC19
map_control_0fac19:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
