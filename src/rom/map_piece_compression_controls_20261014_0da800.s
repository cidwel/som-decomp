.setcpu "65816"
.segment "CODE"
.org $A800
map_control_0da800:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
