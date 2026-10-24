.setcpu "65816"
.segment "CODE"
.org $2A27
map_control_0e2a27:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
