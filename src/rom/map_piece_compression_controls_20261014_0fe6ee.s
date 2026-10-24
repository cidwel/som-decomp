.setcpu "65816"
.segment "CODE"
.org $E6EE
map_control_0fe6ee:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
