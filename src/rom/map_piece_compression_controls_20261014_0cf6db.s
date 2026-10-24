.setcpu "65816"
.segment "CODE"
.org $F6DB
map_control_0cf6db:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
