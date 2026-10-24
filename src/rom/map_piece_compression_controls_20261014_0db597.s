.setcpu "65816"
.segment "CODE"
.org $B597
map_control_0db597:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
