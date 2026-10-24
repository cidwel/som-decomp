.setcpu "65816"
.segment "CODE"
.org $B23B
map_control_0db23b:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
