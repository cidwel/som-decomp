.setcpu "65816"
.segment "CODE"
.org $01C9
map_control_0f01c9:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
