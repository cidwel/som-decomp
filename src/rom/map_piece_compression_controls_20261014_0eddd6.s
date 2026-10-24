.setcpu "65816"
.segment "CODE"
.org $DDD6
map_control_0eddd6:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
