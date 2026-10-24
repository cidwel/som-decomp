.setcpu "65816"
.segment "CODE"
.org $45DD
map_control_0d45dd:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
