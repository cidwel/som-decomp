.setcpu "65816"
.segment "CODE"
.org $BD4A
map_control_0fbd4a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
