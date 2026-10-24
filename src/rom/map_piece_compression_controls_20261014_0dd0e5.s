.setcpu "65816"
.segment "CODE"
.org $D0E5
map_control_0dd0e5:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
