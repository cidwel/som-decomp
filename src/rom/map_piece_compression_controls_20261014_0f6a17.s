.setcpu "65816"
.segment "CODE"
.org $6A17
map_control_0f6a17:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
