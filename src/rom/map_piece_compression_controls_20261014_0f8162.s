.setcpu "65816"
.segment "CODE"
.org $8162
map_control_0f8162:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
