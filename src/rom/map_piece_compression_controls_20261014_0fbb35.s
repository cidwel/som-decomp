.setcpu "65816"
.segment "CODE"
.org $BB35
map_control_0fbb35:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
