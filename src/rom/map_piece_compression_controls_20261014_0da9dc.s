.setcpu "65816"
.segment "CODE"
.org $A9DC
map_control_0da9dc:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
