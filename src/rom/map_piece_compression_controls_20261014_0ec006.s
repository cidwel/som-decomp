.setcpu "65816"
.segment "CODE"
.org $C006
map_control_0ec006:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
