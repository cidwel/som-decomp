.setcpu "65816"
.segment "CODE"
.org $91C6
map_control_0f91c6:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
