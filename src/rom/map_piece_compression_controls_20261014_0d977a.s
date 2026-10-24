.setcpu "65816"
.segment "CODE"
.org $977A
map_control_0d977a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
