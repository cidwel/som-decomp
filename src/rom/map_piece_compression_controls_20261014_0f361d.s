.setcpu "65816"
.segment "CODE"
.org $361D
map_control_0f361d:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
