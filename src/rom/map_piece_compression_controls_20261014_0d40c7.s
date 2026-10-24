.setcpu "65816"
.segment "CODE"
.org $40C7
map_control_0d40c7:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
