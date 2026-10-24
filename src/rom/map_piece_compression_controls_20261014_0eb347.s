.setcpu "65816"
.segment "CODE"
.org $B347
map_control_0eb347:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
