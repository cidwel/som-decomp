.setcpu "65816"
.segment "CODE"
.org $77EC
map_control_0e77ec:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
