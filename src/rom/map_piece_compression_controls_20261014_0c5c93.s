.setcpu "65816"
.segment "CODE"
.org $5C93
map_control_0c5c93:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
