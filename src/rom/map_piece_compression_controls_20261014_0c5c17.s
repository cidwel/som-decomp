.setcpu "65816"
.segment "CODE"
.org $5C17
map_control_0c5c17:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
