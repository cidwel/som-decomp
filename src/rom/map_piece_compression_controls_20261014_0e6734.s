.setcpu "65816"
.segment "CODE"
.org $6734
map_control_0e6734:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
