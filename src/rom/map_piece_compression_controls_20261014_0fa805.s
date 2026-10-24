.setcpu "65816"
.segment "CODE"
.org $A805
map_control_0fa805:
    .byte $EC ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
