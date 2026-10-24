.setcpu "65816"
.segment "CODE"
.org $5066
map_control_0d5066:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
