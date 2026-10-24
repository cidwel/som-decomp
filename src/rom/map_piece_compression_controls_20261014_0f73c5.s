.setcpu "65816"
.segment "CODE"
.org $73C5
map_control_0f73c5:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
