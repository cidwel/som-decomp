.setcpu "65816"
.segment "CODE"
.org $9536
map_control_0f9536:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
