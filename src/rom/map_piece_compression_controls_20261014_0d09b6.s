.setcpu "65816"
.segment "CODE"
.org $09B6
map_control_0d09b6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
