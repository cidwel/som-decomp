.setcpu "65816"
.segment "CODE"
.org $C915
map_control_0ec915:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
