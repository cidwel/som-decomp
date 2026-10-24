.setcpu "65816"
.segment "CODE"
.org $A564
map_control_0da564:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
