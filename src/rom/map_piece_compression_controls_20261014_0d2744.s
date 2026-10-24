.setcpu "65816"
.segment "CODE"
.org $2744
map_control_0d2744:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
