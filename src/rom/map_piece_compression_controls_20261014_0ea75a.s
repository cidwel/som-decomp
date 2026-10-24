.setcpu "65816"
.segment "CODE"
.org $A75A
map_control_0ea75a:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
