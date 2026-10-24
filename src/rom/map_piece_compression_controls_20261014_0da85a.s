.setcpu "65816"
.segment "CODE"
.org $A85A
map_control_0da85a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
