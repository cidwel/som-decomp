.setcpu "65816"
.segment "CODE"
.org $5679
map_control_0d5679:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
