.setcpu "65816"
.segment "CODE"
.org $F8B9
map_control_0ef8b9:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
