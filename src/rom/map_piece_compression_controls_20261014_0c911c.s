.setcpu "65816"
.segment "CODE"
.org $911C
map_control_0c911c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
