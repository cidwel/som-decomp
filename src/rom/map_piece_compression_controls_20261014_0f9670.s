.setcpu "65816"
.segment "CODE"
.org $9670
map_control_0f9670:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
