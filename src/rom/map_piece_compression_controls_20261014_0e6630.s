.setcpu "65816"
.segment "CODE"
.org $6630
map_control_0e6630:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
