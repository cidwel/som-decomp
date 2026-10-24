.setcpu "65816"
.segment "CODE"
.org $A98F
map_control_0da98f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
