.setcpu "65816"
.segment "CODE"
.org $09A3
map_control_0f09a3:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
