.setcpu "65816"
.segment "CODE"
.org $A92A
map_control_0da92a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
