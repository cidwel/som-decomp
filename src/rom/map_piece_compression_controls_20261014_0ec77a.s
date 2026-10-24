.setcpu "65816"
.segment "CODE"
.org $C77A
map_control_0ec77a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
