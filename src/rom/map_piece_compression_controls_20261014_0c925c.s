.setcpu "65816"
.segment "CODE"
.org $925C
map_control_0c925c:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
