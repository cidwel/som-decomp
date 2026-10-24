.setcpu "65816"
.segment "CODE"
.org $88E3
map_control_0e88e3:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
