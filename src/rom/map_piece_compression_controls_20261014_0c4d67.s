.setcpu "65816"
.segment "CODE"
.org $4D67
map_control_0c4d67:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
