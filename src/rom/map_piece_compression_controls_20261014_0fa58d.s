.setcpu "65816"
.segment "CODE"
.org $A58D
map_control_0fa58d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
