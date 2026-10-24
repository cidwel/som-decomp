.setcpu "65816"
.segment "CODE"
.org $8DB4
map_control_0d8db4:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
