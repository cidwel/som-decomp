.setcpu "65816"
.segment "CODE"
.org $A3F3
map_control_0da3f3:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
