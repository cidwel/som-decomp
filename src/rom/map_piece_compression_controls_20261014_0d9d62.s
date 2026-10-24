.setcpu "65816"
.segment "CODE"
.org $9D62
map_control_0d9d62:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
