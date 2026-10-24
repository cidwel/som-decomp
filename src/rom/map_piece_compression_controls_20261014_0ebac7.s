.setcpu "65816"
.segment "CODE"
.org $BAC7
map_control_0ebac7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
