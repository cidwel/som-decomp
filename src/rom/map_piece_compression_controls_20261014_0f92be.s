.setcpu "65816"
.segment "CODE"
.org $92BE
map_control_0f92be:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
