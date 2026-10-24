.setcpu "65816"
.segment "CODE"
.org $91C9
map_control_0c91c9:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
