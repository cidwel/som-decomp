.setcpu "65816"
.segment "CODE"
.org $22E7
map_control_0f22e7:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
