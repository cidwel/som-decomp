.setcpu "65816"
.segment "CODE"
.org $A19A
map_control_0da19a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
