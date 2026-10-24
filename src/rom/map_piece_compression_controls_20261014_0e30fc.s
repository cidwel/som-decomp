.setcpu "65816"
.segment "CODE"
.org $30FC
map_control_0e30fc:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
