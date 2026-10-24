.setcpu "65816"
.segment "CODE"
.org $0CC0
map_control_0f0cc0:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
