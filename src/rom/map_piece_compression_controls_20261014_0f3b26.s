.setcpu "65816"
.segment "CODE"
.org $3B26
map_control_0f3b26:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
