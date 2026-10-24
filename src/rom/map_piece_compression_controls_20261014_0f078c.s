.setcpu "65816"
.segment "CODE"
.org $078C
map_control_0f078c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
