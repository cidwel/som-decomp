.setcpu "65816"
.segment "CODE"
.org $4798
map_control_0d4798:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
