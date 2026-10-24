.setcpu "65816"
.segment "CODE"
.org $2A61
map_control_0d2a61:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
