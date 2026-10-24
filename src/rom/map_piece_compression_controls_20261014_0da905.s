.setcpu "65816"
.segment "CODE"
.org $A905
map_control_0da905:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
