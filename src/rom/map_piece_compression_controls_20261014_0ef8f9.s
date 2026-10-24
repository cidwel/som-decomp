.setcpu "65816"
.segment "CODE"
.org $F8F9
map_control_0ef8f9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
