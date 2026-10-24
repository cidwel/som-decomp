.setcpu "65816"
.segment "CODE"
.org $EF0C
map_control_0fef0c:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
