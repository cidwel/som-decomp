.setcpu "65816"
.segment "CODE"
.org $955C
map_control_0e955c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
