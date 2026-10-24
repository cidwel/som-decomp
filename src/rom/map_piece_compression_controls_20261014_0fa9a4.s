.setcpu "65816"
.segment "CODE"
.org $A9A4
map_control_0fa9a4:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
