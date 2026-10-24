.setcpu "65816"
.segment "CODE"
.org $4D18
map_control_0e4d18:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
