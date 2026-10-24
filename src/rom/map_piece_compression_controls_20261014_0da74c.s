.setcpu "65816"
.segment "CODE"
.org $A74C
map_control_0da74c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
