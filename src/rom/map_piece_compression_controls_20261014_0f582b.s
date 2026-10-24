.setcpu "65816"
.segment "CODE"
.org $582B
map_control_0f582b:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
