.setcpu "65816"
.segment "CODE"
.org $A739
map_control_0da739:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
