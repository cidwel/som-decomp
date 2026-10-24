.setcpu "65816"
.segment "CODE"
.org $6A75
map_control_0f6a75:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
