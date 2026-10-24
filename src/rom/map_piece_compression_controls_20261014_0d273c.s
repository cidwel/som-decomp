.setcpu "65816"
.segment "CODE"
.org $273C
map_control_0d273c:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
