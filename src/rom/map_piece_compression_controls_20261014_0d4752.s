.setcpu "65816"
.segment "CODE"
.org $4752
map_control_0d4752:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
