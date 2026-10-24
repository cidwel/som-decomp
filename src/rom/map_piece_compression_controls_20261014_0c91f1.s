.setcpu "65816"
.segment "CODE"
.org $91F1
map_control_0c91f1:
    .byte $E8 ; backreference distance high bits
    .byte $A9 ; distance low bit/count
