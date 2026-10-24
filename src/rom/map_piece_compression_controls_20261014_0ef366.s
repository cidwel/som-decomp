.setcpu "65816"
.segment "CODE"
.org $F366
map_control_0ef366:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
