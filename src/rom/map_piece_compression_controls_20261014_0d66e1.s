.setcpu "65816"
.segment "CODE"
.org $66E1
map_control_0d66e1:
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E2 ; previous-row copy count
