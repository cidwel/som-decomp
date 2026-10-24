.setcpu "65816"
.segment "CODE"
.org $370F
map_control_0f370f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
