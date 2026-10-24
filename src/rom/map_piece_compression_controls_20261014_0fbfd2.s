.setcpu "65816"
.segment "CODE"
.org $BFD2
map_control_0fbfd2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
