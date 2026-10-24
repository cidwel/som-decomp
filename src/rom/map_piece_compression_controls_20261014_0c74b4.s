.setcpu "65816"
.segment "CODE"
.org $74B4
map_control_0c74b4:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
