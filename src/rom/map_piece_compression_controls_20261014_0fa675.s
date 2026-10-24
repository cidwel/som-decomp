.setcpu "65816"
.segment "CODE"
.org $A675
map_control_0fa675:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
