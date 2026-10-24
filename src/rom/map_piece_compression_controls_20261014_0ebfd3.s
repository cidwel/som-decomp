.setcpu "65816"
.segment "CODE"
.org $BFD3
map_control_0ebfd3:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
