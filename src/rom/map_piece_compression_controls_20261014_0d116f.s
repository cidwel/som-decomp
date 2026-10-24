.setcpu "65816"
.segment "CODE"
.org $116F
map_control_0d116f:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
