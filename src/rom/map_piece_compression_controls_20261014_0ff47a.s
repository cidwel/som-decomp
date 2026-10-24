.setcpu "65816"
.segment "CODE"
.org $F47A
map_control_0ff47a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
