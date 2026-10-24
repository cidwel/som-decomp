.setcpu "65816"
.segment "CODE"
.org $E955
map_control_0fe955:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
