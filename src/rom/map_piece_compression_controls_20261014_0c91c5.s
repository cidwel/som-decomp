.setcpu "65816"
.segment "CODE"
.org $91C5
map_control_0c91c5:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
