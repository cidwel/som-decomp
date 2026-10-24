.setcpu "65816"
.segment "CODE"
.org $1965
map_control_0d1965:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
