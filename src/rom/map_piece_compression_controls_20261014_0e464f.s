.setcpu "65816"
.segment "CODE"
.org $464F
map_control_0e464f:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
