.setcpu "65816"
.segment "CODE"
.org $16C7
map_control_0d16c7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
