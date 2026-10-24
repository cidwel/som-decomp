.setcpu "65816"
.segment "CODE"
.org $A8E2
map_control_0fa8e2:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
