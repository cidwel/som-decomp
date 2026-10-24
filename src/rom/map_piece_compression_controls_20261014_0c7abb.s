.setcpu "65816"
.segment "CODE"
.org $7ABB
map_control_0c7abb:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
