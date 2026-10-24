.setcpu "65816"
.segment "CODE"
.org $D32F
map_control_0dd32f:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
