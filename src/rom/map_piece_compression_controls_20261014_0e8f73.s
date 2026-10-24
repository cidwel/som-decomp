.setcpu "65816"
.segment "CODE"
.org $8F73
map_control_0e8f73:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
