.setcpu "65816"
.segment "CODE"
.org $A390
map_control_0fa390:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
