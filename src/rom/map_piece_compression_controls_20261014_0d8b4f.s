.setcpu "65816"
.segment "CODE"
.org $8B4F
map_control_0d8b4f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
