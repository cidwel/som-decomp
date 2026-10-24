.setcpu "65816"
.segment "CODE"
.org $FC11
map_control_0dfc11:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
