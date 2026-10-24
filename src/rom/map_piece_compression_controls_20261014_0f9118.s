.setcpu "65816"
.segment "CODE"
.org $9118
map_control_0f9118:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
