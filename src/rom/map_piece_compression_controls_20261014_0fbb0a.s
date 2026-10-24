.setcpu "65816"
.segment "CODE"
.org $BB0A
map_control_0fbb0a:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
