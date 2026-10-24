.setcpu "65816"
.segment "CODE"
.org $29A9
map_control_0f29a9:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
