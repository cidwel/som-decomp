.setcpu "65816"
.segment "CODE"
.org $4E32
map_control_0e4e32:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
