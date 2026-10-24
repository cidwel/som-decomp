.setcpu "65816"
.segment "CODE"
.org $1648
map_control_0c1648:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
