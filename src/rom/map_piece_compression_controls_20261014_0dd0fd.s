.setcpu "65816"
.segment "CODE"
.org $D0FD
map_control_0dd0fd:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
