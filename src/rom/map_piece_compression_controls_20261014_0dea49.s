.setcpu "65816"
.segment "CODE"
.org $EA49
map_control_0dea49:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
