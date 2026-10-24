.setcpu "65816"
.segment "CODE"
.org $4E93
map_control_0f4e93:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
