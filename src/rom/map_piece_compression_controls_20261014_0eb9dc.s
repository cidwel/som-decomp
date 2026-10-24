.setcpu "65816"
.segment "CODE"
.org $B9DC
map_control_0eb9dc:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
