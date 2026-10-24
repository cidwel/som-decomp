.setcpu "65816"
.segment "CODE"
.org $E2A0
map_control_0de2a0:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
