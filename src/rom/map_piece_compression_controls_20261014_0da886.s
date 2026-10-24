.setcpu "65816"
.segment "CODE"
.org $A886
map_control_0da886:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
