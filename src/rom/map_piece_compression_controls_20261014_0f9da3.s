.setcpu "65816"
.segment "CODE"
.org $9DA3
map_control_0f9da3:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
