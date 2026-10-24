.setcpu "65816"
.segment "CODE"
.org $E8F3
map_control_0fe8f3:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
