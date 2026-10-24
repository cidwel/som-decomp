.setcpu "65816"
.segment "CODE"
.org $923C
map_control_0c923c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
