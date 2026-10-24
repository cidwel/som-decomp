.setcpu "65816"
.segment "CODE"
.org $9773
map_control_0f9773:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
