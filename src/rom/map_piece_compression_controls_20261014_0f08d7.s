.setcpu "65816"
.segment "CODE"
.org $08D7
map_control_0f08d7:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
