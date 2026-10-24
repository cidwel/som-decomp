.setcpu "65816"
.segment "CODE"
.org $A8F7
map_control_0da8f7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
