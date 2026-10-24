.setcpu "65816"
.segment "CODE"
.org $3A19
map_control_0f3a19:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
