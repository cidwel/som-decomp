.setcpu "65816"
.segment "CODE"
.org $B660
map_control_0eb660:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
