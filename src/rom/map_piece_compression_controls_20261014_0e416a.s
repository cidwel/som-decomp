.setcpu "65816"
.segment "CODE"
.org $416A
map_control_0e416a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
