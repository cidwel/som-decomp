.setcpu "65816"
.segment "CODE"
.org $9D09
map_control_0d9d09:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
