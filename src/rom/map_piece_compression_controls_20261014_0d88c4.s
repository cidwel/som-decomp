.setcpu "65816"
.segment "CODE"
.org $88C4
map_control_0d88c4:
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
