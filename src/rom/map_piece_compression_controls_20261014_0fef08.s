.setcpu "65816"
.segment "CODE"
.org $EF08
map_control_0fef08:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
