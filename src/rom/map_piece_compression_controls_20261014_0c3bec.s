.setcpu "65816"
.segment "CODE"
.org $3BEC
map_control_0c3bec:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
