.setcpu "65816"
.segment "CODE"
.org $488C
map_control_0d488c:
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
