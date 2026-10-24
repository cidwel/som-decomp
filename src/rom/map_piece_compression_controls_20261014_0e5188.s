.setcpu "65816"
.segment "CODE"
.org $5188
map_control_0e5188:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
