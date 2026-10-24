.setcpu "65816"
.segment "CODE"
.org $70FA
map_control_0f70fa:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
