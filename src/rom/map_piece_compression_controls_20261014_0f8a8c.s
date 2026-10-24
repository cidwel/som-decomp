.setcpu "65816"
.segment "CODE"
.org $8A8C
map_control_0f8a8c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
