.setcpu "65816"
.segment "CODE"
.org $B744
map_control_0eb744:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
