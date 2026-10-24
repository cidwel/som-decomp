.setcpu "65816"
.segment "CODE"
.org $C67B
map_control_0ec67b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
