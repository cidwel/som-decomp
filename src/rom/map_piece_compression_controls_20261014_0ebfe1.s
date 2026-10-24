.setcpu "65816"
.segment "CODE"
.org $BFE1
map_control_0ebfe1:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
