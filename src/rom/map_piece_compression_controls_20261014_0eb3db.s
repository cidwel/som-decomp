.setcpu "65816"
.segment "CODE"
.org $B3DB
map_control_0eb3db:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
