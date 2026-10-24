.setcpu "65816"
.segment "CODE"
.org $B837
map_control_0db837:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
