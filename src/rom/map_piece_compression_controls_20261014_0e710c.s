.setcpu "65816"
.segment "CODE"
.org $710C
map_control_0e710c:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
