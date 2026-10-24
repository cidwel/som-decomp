.setcpu "65816"
.segment "CODE"
.org $772B
map_control_0f772b:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
