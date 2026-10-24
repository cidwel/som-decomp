.setcpu "65816"
.segment "CODE"
.org $4BE2
map_control_0c4be2:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
