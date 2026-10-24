.setcpu "65816"
.segment "CODE"
.org $B20C
map_control_0fb20c:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
