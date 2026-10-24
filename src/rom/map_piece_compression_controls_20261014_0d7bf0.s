.setcpu "65816"
.segment "CODE"
.org $7BF0
map_control_0d7bf0:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
