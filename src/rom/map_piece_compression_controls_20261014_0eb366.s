.setcpu "65816"
.segment "CODE"
.org $B366
map_control_0eb366:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
