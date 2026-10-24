.setcpu "65816"
.segment "CODE"
.org $2A07
map_control_0e2a07:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
