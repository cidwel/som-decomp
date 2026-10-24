.setcpu "65816"
.segment "CODE"
.org $9D73
map_control_0d9d73:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
