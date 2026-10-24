.setcpu "65816"
.segment "CODE"
.org $373C
map_control_0f373c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
