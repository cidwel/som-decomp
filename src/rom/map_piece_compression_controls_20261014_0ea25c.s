.setcpu "65816"
.segment "CODE"
.org $A25C
map_control_0ea25c:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
