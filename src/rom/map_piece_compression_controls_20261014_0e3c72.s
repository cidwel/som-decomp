.setcpu "65816"
.segment "CODE"
.org $3C72
map_control_0e3c72:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
