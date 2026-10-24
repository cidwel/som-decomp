.setcpu "65816"
.segment "CODE"
.org $A817
map_control_0da817:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
