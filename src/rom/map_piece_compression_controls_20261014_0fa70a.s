.setcpu "65816"
.segment "CODE"
.org $A70A
map_control_0fa70a:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
