.setcpu "65816"
.segment "CODE"
.org $2616
map_control_0d2616:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
