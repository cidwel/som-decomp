.setcpu "65816"
.segment "CODE"
.org $C981
map_control_0ec981:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
