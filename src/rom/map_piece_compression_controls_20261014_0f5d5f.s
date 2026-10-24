.setcpu "65816"
.segment "CODE"
.org $5D5F
map_control_0f5d5f:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E7 ; previous-row copy count
