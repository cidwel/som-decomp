.setcpu "65816"
.segment "CODE"
.org $A70C
map_control_0da70c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
