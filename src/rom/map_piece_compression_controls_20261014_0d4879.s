.setcpu "65816"
.segment "CODE"
.org $4879
map_control_0d4879:
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
