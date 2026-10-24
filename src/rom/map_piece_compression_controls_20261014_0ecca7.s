.setcpu "65816"
.segment "CODE"
.org $CCA7
map_control_0ecca7:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
