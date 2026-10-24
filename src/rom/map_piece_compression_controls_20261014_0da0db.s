.setcpu "65816"
.segment "CODE"
.org $A0DB
map_control_0da0db:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
