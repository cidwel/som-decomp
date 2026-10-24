.setcpu "65816"
.segment "CODE"
.org $A7F2
map_control_0fa7f2:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
