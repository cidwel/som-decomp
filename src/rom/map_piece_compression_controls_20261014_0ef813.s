.setcpu "65816"
.segment "CODE"
.org $F813
map_control_0ef813:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
