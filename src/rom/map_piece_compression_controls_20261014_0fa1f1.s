.setcpu "65816"
.segment "CODE"
.org $A1F1
map_control_0fa1f1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
