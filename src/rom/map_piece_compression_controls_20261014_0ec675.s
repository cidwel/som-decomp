.setcpu "65816"
.segment "CODE"
.org $C675
map_control_0ec675:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
