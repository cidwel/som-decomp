.setcpu "65816"
.segment "CODE"
.org $EF20
map_control_0fef20:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
