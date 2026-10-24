.setcpu "65816"
.segment "CODE"
.org $370C
map_control_0f370c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
