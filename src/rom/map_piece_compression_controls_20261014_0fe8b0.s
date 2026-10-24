.setcpu "65816"
.segment "CODE"
.org $E8B0
map_control_0fe8b0:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
