.setcpu "65816"
.segment "CODE"
.org $6AA9
map_control_0c6aa9:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
