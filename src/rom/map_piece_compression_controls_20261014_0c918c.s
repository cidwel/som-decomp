.setcpu "65816"
.segment "CODE"
.org $918C
map_control_0c918c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
