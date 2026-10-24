.setcpu "65816"
.segment "CODE"
.org $0693
map_control_0f0693:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
