.setcpu "65816"
.segment "CODE"
.org $9669
map_control_0f9669:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
