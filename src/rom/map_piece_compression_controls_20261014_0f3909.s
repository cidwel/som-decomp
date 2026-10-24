.setcpu "65816"
.segment "CODE"
.org $3909
map_control_0f3909:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
