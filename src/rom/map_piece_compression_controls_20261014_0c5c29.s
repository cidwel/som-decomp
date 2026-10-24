.setcpu "65816"
.segment "CODE"
.org $5C29
map_control_0c5c29:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
