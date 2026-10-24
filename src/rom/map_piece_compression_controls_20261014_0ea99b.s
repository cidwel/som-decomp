.setcpu "65816"
.segment "CODE"
.org $A99B
map_control_0ea99b:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
