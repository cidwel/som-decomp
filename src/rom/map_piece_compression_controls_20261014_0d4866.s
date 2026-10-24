.setcpu "65816"
.segment "CODE"
.org $4866
map_control_0d4866:
    .byte $E8 ; backreference distance high bits
    .byte $A1 ; distance low bit/count
