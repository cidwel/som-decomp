.setcpu "65816"
.segment "CODE"
.org $70A4
map_control_0f70a4:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
