.setcpu "65816"
.segment "CODE"
.org $457C
map_control_0e457c:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
