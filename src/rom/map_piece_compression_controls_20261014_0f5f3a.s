.setcpu "65816"
.segment "CODE"
.org $5F3A
map_control_0f5f3a:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
